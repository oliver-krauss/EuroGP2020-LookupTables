/*WBL 19 May 2018 based on main.c r1.8  */
#define Version "$Revision: 1.7 $"

//Compile2.bat

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//#include <ctype.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>

#include "t_cbrt.c"
//#include "e_sqrt.c"

double read_double(const char* text);
void print_double(const double x);
double tweak_double(const double x, const int epsilon);
double table_ieee754_cbrt (double x);

void print2(const char* text, const double out, const double diff) {
  printf("%s",text);
  print_double(out);
  printf(" cubed ");
  print_double(out*out*out);
  printf(" diff %g\n",diff);
}

int main(int argc, char *argv[]){



  printf("%s %s argc %d %s\n",__FILE__,Version,argc,(argc>1)? argv[1]:"\"\"");
  const double input = (argc>1 && argv[1][0])?
    ((strncmp(argv[1],"0x",2)==0)? read_double(argv[1]) : atof(argv[1])) : 1.0;

  printf("table_ieee754_cbrt ");print_double(input);printf("\n");

  const double out  = table_ieee754_cbrt(input);
  const double diff = input-out*out*out;

  printf("table_ieee754_cbrt(%g) ",input);
  print2("is ",out,diff);

  const double smaller = out/(1+DBL_EPSILON);
  const double larger  = out*(1+DBL_EPSILON);

  const double d_smaller = input-smaller*smaller*smaller;
  const double d_larger  = input- larger*larger *larger;

  print2("smaller ",smaller,d_smaller);
  print2("larger  ", larger,d_larger);

  double error = DBL_MAX; int I; double best;
  for(int i=-9;i<=9;i++){
    const double test   = tweak_double(out,i);
    const double d_test = input- test*test*test;
    printf("test %2d ",i);
    print2("",test,d_test);
    if((fabs(d_test)<error) || (fabs(d_test)==error && abs(i)<abs(I))){
      error=fabs(d_test); I=i; best=test;
    }
  }

  // inserted stuff for checking cube root with other implementations
  int Digs = DECIMAL_DIG;
  printf("Reversed %.*e\n", Digs, best*best*best);
  printf("C   Bprc %.*e", Digs, best);
  printf(" Bhex %a\n", best);
//    for (int j = 0; j < 1000; j++) {
//        clock_t t;
//        t = clock();
//        for (long i = 0; i < 1000000; i++) {
//            sqrt(i);
//        }
//        t = clock() - t;
//        double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
//        printf("time %.*e\n", Digs, time_taken);
//    }


  printf("Best local estimate %d ",I);
  print2("",best,error);
  if(I>= -1 && I<= 1) return EXIT_SUCCESS;

  if(fabs(d_smaller)<fabs(diff)){printf("SMALLER CLOSER\n");return EXIT_FAILURE;}
  if(fabs(d_larger) <fabs(diff)){printf("LARGER  CLOSER\n");return EXIT_FAILURE;}

  return EXIT_SUCCESS;
}
