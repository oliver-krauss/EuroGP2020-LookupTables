/* WBL 19 May 2018 based on example_short.c */
#define Version "$Revision: 1.9 $"

#include <stdio.h>
#include <stdlib.h> /* free() */
#include <stddef.h> /* NULL */
#include "cmaes_interface.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include <assert.h>

float __t_cbrt[1024];

double input;
uint32_t t_cbrt_idx;
uint32_t table_cbrt_idx(const double x);
double fitfun(double const *x, int dim); 

/* the optimization loop */
int main(int argc, char *argv[]) {
  cmaes_t evo; /* an CMA-ES type struct or "object" */
  double *arFunvals, *const*pop, *xfinal;
  int i,I=0;
  printf("%s %s ",__FILE__,Version); fflush(stdout);

  I++;
  input = (argc>I && argv[I][0])? atof(argv[I]): 1.0;
  t_cbrt_idx = table_cbrt_idx(input);
  I++;
  const long seed = (argc>I && argv[I][0])? atol(argv[I]): 0;
  I++;
  double *initialX = (argc>I+1)? calloc(2,sizeof(double)) : NULL;
  if(argc>I+1) {
    initialX[0] = atof(argv[I]);
    initialX[1] = atof(argv[I+1]);
  } else if(argc>I) {fprintf(stderr,"Bad command line %d %s\n",argc,argv[I]); exit(2);}
  I+=2;
  double *initialStdDev = (argc>I+1)? calloc(2,sizeof(double)) : NULL;
  if(argc>I+1) {
    initialStdDev[0] = atof(argv[I]);
    initialStdDev[1] = atof(argv[I+1]);
  } else if(argc>I) {fprintf(stderr,"Bad cmd line %d %s\n",argc,argv[I]); exit(3);}

  printf("%0.17f %d seed %ld ",input,t_cbrt_idx,seed);
  if(initialX)      printf("%g %g, ",initialX[0],     initialX[1]);
  if(initialStdDev) printf("%g %g; ",initialStdDev[0],initialStdDev[1]);
  printf("argc %d ",argc);
  for(i=1;i<argc;i++) printf("%s ",(argv[i][0])? argv[i] : "\"\"");
  printf("\n");

  memset(__t_cbrt,0,512*sizeof(float)); /*Ensure correct use of __t_cbrt*/

  /* Initialize everything into the struct evo, 0 means default */
  /* cbrt.par based on cmaes_initials.par two dimensions */
  arFunvals = cmaes_init(&evo, 2, initialX, initialStdDev, seed, 0, "cbrt.par");

  printf("%s\n", cmaes_SayHello(&evo));
  /*Leave cmaes_ReadSignalswhilst debugging*/
  cmaes_ReadSignals(&evo, "cmaes_signals.par");

  /* Iterate until stop criterion holds */
  while(!cmaes_TestForTermination(&evo))
    { 
      /* generate lambda new search points, sample population */
      pop = cmaes_SamplePopulation(&evo); /* do not change content of pop */

      /* evaluate the new search points using fitfun */
      for (i = 0; i < cmaes_Get(&evo, "lambda"); ++i) {
    	  arFunvals[i] = fitfun(pop[i], (int) cmaes_Get(&evo, "dim"));
      }

      /* update the search distribution used for cmaes_SamplePopulation() */
      cmaes_UpdateDistribution(&evo, arFunvals);  

      /* read instructions for printing output or changing termination conditions */ 
      cmaes_ReadSignals(&evo, "cmaes_signals.par");
      fflush(stdout); /* useful in MinGW */
    }
  printf("Stop:\n%s\n",  cmaes_TestForTermination(&evo)); /* print termination reason */
  cmaes_WriteToFile(&evo, "all", "allcmaes.dat");         /* write final results */

  /* get best estimator for the optimum, xmean */
  xfinal = cmaes_GetNew(&evo, "xmean"); /* "xbestever" might be used as well */
  cmaes_exit(&evo); /* release memory */ 

  /* do something with final solution and finally release memory */
  free(xfinal); 

  return 0;
}

