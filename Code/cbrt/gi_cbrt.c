/* WBL 18 May 2018 based on e_sqrt.c r1.6  $Revision: 1.20 $ */
/* Double-precision floating point square root.
   Copyright (C) 1997-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*Modifications:
WBL and Oliver Krauss 20 Aug 2019 fixed denorm bug that used incorrect cube root of 2^108
WBL 26 Jun 2018 For release kit, consolidate different versions
WBL 21 May 2018 Reverted back to r1.10 for testing mode,
           add read_double,print_double,tweak_double
WBL 18 May 2018 hack from sqrt to cbrt
 */

#ifndef NDEBUG
#include <stdio.h>
#include <assert.h>
#endif

#include <math.h>
#include <math_private.h>
//#include <fenv_libc.h> powerpc specific
#include <inttypes.h>
#include <stdint.h>
#include <sysdep.h>
#include <ldsodefs.h>

double table_ieee754_cbrt (double x);
/*for CMA-ES*/
/* the objective (fitness) function to be minimized */
/* Try 3 fitness cases */
double test(const double input) {  /*based on main2.c 1.3*/
  printf("table_ieee754_cbrt(%0.17f) ",input); fflush(stdout);
  const double out  = table_ieee754_cbrt(input);
  const double diff = input-out*out*out;

  printf("is %0.17f cubed %g diff %g\n",out, out*out*out, diff);

  if(fabs(diff) > 1e-14) return fabs(diff);

  const double smaller = out/(1+DBL_EPSILON);
  const double larger  = out*(1+DBL_EPSILON);

  const double d_smaller = input-smaller*smaller*smaller;
  const double d_larger  = input- larger*larger *larger;


  printf("smaller %0.17f cubed %g diff %g\n",
	 smaller, smaller*smaller*smaller, d_smaller);
  printf("larger  %0.17f cubed %g diff %g\n",
	 larger,   larger*larger *larger,  d_larger);

  if(fabs(d_smaller)<fabs(diff)) return fabs(diff);
  if(fabs(d_larger) <fabs(diff)) return fabs(diff);

  return 0.0;
}

//hmm perhaps CMA_ES not good with tiny values, try log
double loglike(const double diff) {
  if(diff==0.0) return diff;
  if(diff< 1.0) return (-log(DBL_EPSILON))+log(diff);
  return (-log(DBL_EPSILON))+diff;
}

extern float __t_cbrt[1024];
extern const double input;
extern const uint32_t t_cbrt_idx;
double fitfun(double const *x, int N) {
  assert(N==2);
  __t_cbrt[t_cbrt_idx]   = (float) x[0];
  __t_cbrt[t_cbrt_idx+1] = (float) x[1];

  double diff[3];
  double sum = 0;
  ieee_double_shape_type ew_u;
  ew_u.value = input;
  //printf("input ew_u 0x%08x,%08x\n",ew_u.parts.msw,ew_u.parts.lsw);

  ew_u.parts.msw = ew_u.parts.msw & 0xfffff800; //clear all of lower fraction part
  ew_u.parts.lsw = 0;
  //printf("lowpoint ew_u 0x%08x,%08x %0.17f\n",ew_u.parts.msw,ew_u.parts.lsw,ew_u.value);
  diff[0] = test(ew_u.value);

  ew_u.parts.msw = ew_u.parts.msw | 0x00000400; //set mid bit only
  //printf("midpoint ew_u 0x%08x,%08x %0.17f\n",ew_u.parts.msw,ew_u.parts.lsw,ew_u.value);
  diff[1] = test(ew_u.value);

  ew_u.parts.msw = ew_u.parts.msw | 0x000007ff; //set all lower fraction part
  ew_u.parts.lsw = 0xffffffff;
  //printf("toppoint ew_u 0x%08x,%08x %0.17f\n",ew_u.parts.msw,ew_u.parts.lsw,ew_u.value);
  diff[2] = test(ew_u.value);

  for(int i=0;i<3;i++) {
    const double ldif = loglike(diff[i]);
    sum += ldif;
  }
  printf("fitfun x %g,%g %g ",x[0],x[1],sum);
  for(int i=0;i<3;i++) {
    const double ldif = loglike(diff[i]);
    printf("diff[%d] %g ldif %g ",i,diff[i],ldif);
  }
  printf("\n");

  if(sum==0) printf("DONE t_cbrt_idx %d %0.17f %0.17f\n",t_cbrt_idx,__t_cbrt[t_cbrt_idx],__t_cbrt[t_cbrt_idx+1]);

  return sum;
}

uint32_t table_cbrt_idx(const double x){
  ieee_double_shape_type ew_u;
  ew_u.value = (x);
  const uint32_t xi0 = ew_u.parts.msw;
  return (xi0 >> (52 - 32 - 9 - 1) & 0x3fe);
}

#ifndef _ARCH_PPCSQ

/*glibc-2.27/sysdeps/ieee754/dbl-64/s_cbrt.c */
#define CBRT2 1.2599210498948731648		/* 2^(1/3) */
#define SQR_CBRT2 1.5874010519681994748		/* 2^(2/3) */

#define __builtin_fma(a, b, c) (((a)*(b))+(c))

/* from sysdeps/powerpc/fpu/fenv_libc.h, ie powerpc specific
This operation (i) sets the appropriate FPSCR bits for its
   parameter, (ii) converts sNaN to the corresponding qNaN, and (iii)
   otherwise passes its parameter through unchanged (in particular, -0
   and +0 stay as they were).  The `obvious' way to do this is optimised
   out by gcc.
#define f_wash(x) \
   ({ double d; asm volatile ("fmul %0,%1,%2" \
			      : "=f"(d) \
			      : "f" (x), "f"((float)1.0)); d; })
*/
#define f_wash(x) (x)

double read_double(const char* text){
    printf("Recompile worked");
  ieee_double_shape_type ew_u;
  const int check = sscanf(text,"%x,%x",&ew_u.parts.msw,&ew_u.parts.lsw);
  assert(check==2);
  return ew_u.value;
}

void print_double(const double x){
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  printf("%g 0x%08x,%08x",x,ew_u.parts.msw,ew_u.parts.lsw);
}

double tweak_double(const double x, const int epsilon){
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  long unsigned int temp = ew_u.parts.lsw + epsilon;
  if(temp > 0xffffffff) {
    fprintf(stderr,"tweak_double(%g,%d) overflowed lsw 0x%lx\n",x,epsilon,temp);}
  ew_u.parts.lsw = temp;
  return ew_u.value;
}

//static const double almost_half = 0.5000000000000001;	/* 0.5 + 2^-53 */
static const double almost_third = 0.3333333333333334;	/* 1/3 + 2^-53 */
static const ieee_float_shape_type a_nan = {.word = 0x7fc00000 };
static const ieee_float_shape_type a_inf = {.word = 0x7f800000 };
static const float two108 = 3.245185536584267269e+32;
//static const float twom54 = 5.551115123125782702e-17;
static const float twom36 = 1.4551915228366852E-11;
//extern const float __t_cbrt[1024];

/* WBL do not worry about speed, see if can get table approach to work! 
   treat comments with caution many are from powerpc sqrt

   The method is based on a description in
   Computation of elementary functions on the IBM RISC System/6000 processor,
   P. W. Markstein, IBM J. Res. Develop, 34(1) 1990.
   Basically, it consists of two interleaved Newton-Raphson approximations,
   one to find the actual square root, and one to find its reciprocal
   without the expense of a division operation.   The tricky bit here
   is the use of the POWER/PowerPC multiply-add operation to get the
   required accuracy with high speed.

   The argument reduction works by a combination of table lookup to
   obtain the initial guesses, and some careful modification of the
   generated guesses (which mostly runs on the integer unit, while the
   Newton-Raphson is running on the FPU).  */

double cbrt(const double x)
{
#ifndef NDEBUG
{
//  printf("cbrt (%0.21f ",x);
//  print_double(x);
//  printf(")\n");
}
#endif

  const float inf = a_inf.value;

      /* schedule the EXTRACT_WORDS to get separation between the store
	 and the load.  */
      ieee_double_shape_type ew_u;
      ieee_double_shape_type iw_u;
      ew_u.value = (x);
      if (x != inf)
	{
	  /* Variables named starting with 's' exist in the
	     argument-reduced space, so that 2 > sx >= 0.5,
	     1.41... > sg >= 0.70.., 0.70.. >= sy > 0.35... .
	     Variables named ending with 'i' are integer versions of
	     floating-point values.  */
	  double sx;	/* The value of which we're trying to find the
			   square root.  */
	  double sg, g;	/* Guess of the square root of x.  */
	  double sd, d;	/* Difference between the square of the guess and x.  */
	  double sy;	/* Estimate of 1/2g (overestimated by 1ulp).  */
	  double sy2;	/* 1.5*sy *** 2*sy */
	  double e;	/* Difference between y*g and 1/2 (se = e * fsy).  */
	  double shx;	/* == sx * fsg */
	  double fsg;	/* sg*fsg == g.  */
	  /* fenv_t fe;	   Saved floating-point environment (stores rounding
			   mode and whether the inexact exception is
			   enabled).  */
	  uint32_t xi0, xi1, sxi, fsgi;
	  const float *t_cbrt;

	  //fe = fegetenv_register ();
	  /* complete the EXTRACT_WORDS (xi0,xi1,x) operation.  */
	  xi0 = ew_u.parts.msw;
	  xi1 = ew_u.parts.lsw;
	  //relax_fenv_state ();
	  //for cbrt normalise whole of exponent => reorganise __t_cbrt
	  sxi = (xi0 & 0x3fffffff) | 0x3ff00000;
	  /* schedule the INSERT_WORDS (sx, sxi, xi1) to get separation
	     between the store and the load.  */
	  iw_u.parts.msw = sxi;
	  iw_u.parts.lsw = xi1;
	  //for cbrt do not overlap with exponent
	  const uint32_t t_cbrt_idx = (xi0 >> (52 - 32 - 9 - 1) & 0x3fe);
	  t_cbrt = __t_cbrt + t_cbrt_idx;
	  sg = t_cbrt[0];
	  sy = t_cbrt[1];
	  //printf("Table[%d] values %g %g\n",t_cbrt_idx,sg,sy);
	  /* complete the INSERT_WORDS (sx, sxi, xi1) operation.  */
	  sx = iw_u.value;

	  /* Here we have three Newton-Raphson iterations each of a
	     division and a square root and the remainder of the
	     argument reduction, all interleaved.   */
	  sd = -__builtin_fma (sg, sg*sg, -sx);
	  //printf("Normalised target %g initial error %g\n",sx,sd);
	  //fsgi = (xi0 + 0x40000000) >> 1 & 0x7ff00000;
	  //divide exponent by three no where as clean as by two
	  //const int signed_expi = xi0 & 0x3ff00000;
	  const uint32_t expi = (xi0 >> 20) & 0x7ff;
	  int exp3i;
	  int exp3r;
	  const int exp = expi-1023;
	  if(exp>=0) {
	    exp3i = exp/3;
	    exp3r = exp%3;
	  } else {
	    const int i = -exp;
	    exp3i = -(i/3);
	    exp3r = -(i%3);
	  }
	  fsgi = (exp3i+1023) << 20;

	  sy2 = 1.5*sy;
	  sg = __builtin_fma (sy, sd, sg);	/* 16-bit approximation to
						   sqrt(sx). */

	  /* schedule the INSERT_WORDS (fsg, fsgi, 0) to get separation
	     between the store and the load.  */
	  /* Set a double from two 32 bit ints.  **
	     ie fsg <= fsgi
	     do { ieee_double_shape_type iw_u; iw_u.parts.msw = (fsgi); iw_u.parts.lsw = (0); (fsg) = iw_u.value; } while (0);
	  */
	  INSERT_WORDS (fsg, fsgi, 0);
	  iw_u.parts.msw = fsgi;
	  iw_u.parts.lsw = (0);
	  e = -__builtin_fma (sy, sg*sg, -almost_third);
	  sd = -__builtin_fma (sg, sg*sg, -sx);
	  //printf("Second estimate %0.17f 2nd error %g\n",sg,sd);
	  if ((xi0 & 0x7ff00000) == 0) {
	    goto denorm;
      }
	  sy = __builtin_fma (e, sy2, sy);
	  sg = __builtin_fma (sy, sd, sg);	/* 32-bit approximation to
						   sqrt(sx).  */
	  sy2 = 1.5*sy;
	  /* complete the INSERT_WORDS (fsg, fsgi, 0) operation.  */
	  fsg = iw_u.value;
	  switch(exp3r){
	  case 2:
	    fsg *= SQR_CBRT2;
	    break;
	  case 1:
	    fsg *= CBRT2;
	    break;
	  case -2:
	    fsg /= SQR_CBRT2;
	    break;
	  case -1:
	    fsg /= CBRT2;
	    break;
	  case 0:;
	  }
	  //printf("xi0 0x%08x expi %d exp %d exp3i %d exp3r %d fsgi 0x%08x fsg %g %g\n",xi0,expi,exp,exp3i,exp3r,fsgi,iw_u.value,fsg);

	  e = -__builtin_fma (sy, sg*sg, -almost_third);
	  sd = -__builtin_fma (sg, sg*sg, -sx);
	  sy = __builtin_fma (e, sy2, sy);
	  shx = sx * fsg;
	  sg = __builtin_fma (sy, sd, sg);	/* 64-bit approximation to
						   sqrt(sx), but perhaps
						   rounded incorrectly.  */
	  //printf("last normalised estimate %0.17f sy %g shx %g\n",sg,sy,shx);

	  sy2 = 1.5*sy;
	  g = sg * fsg;
	  e = -__builtin_fma (sy, sg*sg, -almost_third);
	  d = -__builtin_fma (g, sg*sg, -shx);
	  sy = __builtin_fma (e, sy2, sy);
	  //printf("sy %g shx %g last estimate %0.17f error %g\n",sy,shx,g,d);
	  //fesetenv_register (fe);
	  return __builtin_fma (sy, d, g);
	denorm:
	  //assert(0); //Only get here with fuzz_int.bat
	  /* For denormalised numbers, we normalise, calculate the
	     square root, and return an adjusted result.  */
	  //fesetenv_register (fe);

	  return cbrt(x * two108) * twom36;
	}
      else{ return a_nan.value; } //for inf do same as sqrt ie return nan
}
#endif /* _ARCH_PPCSQ  */

double
table_ieee754_cbrt (const double x) {
  if(x < 0) return -cbrt(0.0-x);
  if(x > 0) return cbrt(x);
  return x;
}
