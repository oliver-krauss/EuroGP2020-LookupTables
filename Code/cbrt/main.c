/*WBL 17 May 2018 "$Revision: 1.8 $" */

//Compile: gcc main.c

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//#include <ctype.h>
//#include <unistd.h>
//#include <string.h>

#include "t_sqrt.c"
//#include "e_sqrt.c"

#define sqrt __ieee754_sqrt
double __ieee754_sqrt (const double x);

int main(int argc, char *argv[]){
  const double input = (argc>1 && argv[1])? atof(argv[1]) : 1.0;

  printf("sqrt(%g)\n",input); //fflush(stdout);

  const double out  = sqrt(input);
  const double diff = input-out*out;

  printf("sqrt(%g) ",input); fflush(stdout);
  printf("is %f squared %g diff %g\n",out, out*out, diff);

  const double smaller = out/(1+DBL_EPSILON);
  const double larger  = out*(1+DBL_EPSILON);

  const double d_smaller = input-smaller*smaller;
  const double d_larger  = input- larger*larger;


  printf("smaller %f squared %g diff %g\n",
	 smaller, smaller*smaller, d_smaller);
  printf("larger  %f squared %g diff %g\n",
	 larger,   larger*larger,  d_larger);

  if(fabs(d_smaller)<fabs(diff)){printf("SMALLER CLOSER\n");return EXIT_FAILURE;}
  if(fabs(d_larger) <fabs(diff)){printf("LARGER  CLOSER\n");return EXIT_FAILURE;}

  return EXIT_SUCCESS;
}
