/**
 * Harness for CMA-ES to produce the values in lookupTable.h with the function in cmaesRunner.h
 * @author Oliver Krauss @date 21 Aug 2019
 */
#define Version "$Revision: 1.0 $"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include "c-cmaes-master/src/cmaes_interface.h"
#include "lookupTable.h"
#include "fitfun.h"

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int MAX_RETRIES = 1;

int main(int argc, char *argv[]) {
    // get filename from own name
    char* fileName = (argc > 0 && argv[0][0]) ? argv[0] : 0;
    fileName = strstr(fileName, "_");
    fileName++;

    // load seed and file to modify from input or use 0
    long seed = (argc > 1 && argv[1][0]) ? atol(argv[1]) : 0;

    printf("Running Optimization on fitness %s with seed %li \n", fileName, seed);

    // the result we want to write to lookupTable.c
    double newTable[table_size];

    // the actual CMA_ES run
    cmaes_t evo;

    // the vector containing the evaluations of the population
    double *arFunvals;

    // value currently being optimized
    initFitnessValues();
    double stepSize = (higher_end - lower_end) / table_size;
    double value = lower_end - stepSize / 2;

    // population of CMAES run
    double *const *pop;

    // loop through all values of the script
    for (int i = 0; i < table_size; i++) {
        value += stepSize;

        int success = false;
        int retries = 0;
        while (!success && retries < MAX_RETRIES) {
            /* Initialize everything into the struct evo, 0 means default */
            double *initialX = calloc(1, sizeof(double));
            double *initialStdDev = calloc(1, sizeof(double));
             // initial guess doesn't matter as long as it isn't something completely insane
             if (i == 0) {
                 initialX[0] = value;
             } else {
                 initialX[0] = newTable[i-1];
             }
            initialStdDev[0] = 0.618351; // random guess
            arFunvals = cmaes_init(&evo, 1, initialX, initialStdDev, seed, 0, "cmaes.par");

            while (!cmaes_TestForTermination(&evo)) {
                /* generate lambda new search points, , as sample population */
                pop = cmaes_SamplePopulation(&evo); /* do not change content of pop */

                /* evaluate the new search points using fitfun */
                for (int j = 0; j < cmaes_Get(&evo, "lambda"); ++j) {
                    arFunvals[j] = fitfun(pop[j], (int) cmaes_Get(&evo, "dim"), value);
                }

                /* update the search distribution used for cmaes_SamplePopulation() */
                cmaes_UpdateDistribution(&evo, arFunvals);
            }

            // show reason for termination to user and print log to file
            //printf("Stop: %s", cmaes_TestForTermination(&evo));
            cmaes_WriteToFile(&evo, "all", "allcmaes.dat");

            // load target value to string
            double *targetValue = cmaes_GetNew(&evo, "xbestever");

            // set with our first guess
            if (retries == 0) {
                newTable[i] = targetValue[0];
            }

            if (strstr(cmaes_TestForTermination(&evo), "<= stopFitness (0.00e+00)") != NULL) {
                success = true;
            } else if (retries == (MAX_RETRIES - 1) && (
                    // strstr(cmaes_TestForTermination(&evo), "TolFun: function value differences 0.00e+00 < stopTolFun=0.00e+00\n") ||
                     strstr(cmaes_TestForTermination(&evo), "NoEffectAxis: standard deviation 0.1*7.84e-16 in principal axis 0 without effect\n") ||
                    strstr(cmaes_TestForTermination(&evo), "history of function value changes 0.00e+00") != NULL)) {
                // we found the closest possible, will probably never get to 0
                success = true;
            } else {
                seed++;
                retries++;
            }

            // compare our current best guess with our newest value and decide
            double best[1];
            best[0] = newTable[i];

            if (best[0] != targetValue[0]) {
                double qualityTarget = fitfun(targetValue, 1, value);
                double qualityCurrentBest = fitfun(best, 1, value);

                if (qualityCurrentBest == qualityTarget) {
                    // we might have accidentally hit an inflection point, use a different fitness comparison
                    // TODO make decision based on random position in range
                    int asdfsadf = 0;
                }

                if (qualityCurrentBest > qualityTarget) {
                    newTable[i] = targetValue[0];
                    lookupTable[i] = newTable[i];
                }
            }


            // inform user of found values
            if (success) {
                char selectedValue[29];
                snprintf(selectedValue, 29, "%.*e", DECIMAL_DIG, newTable[i]);
                printf("Did %i - val %e is fn(%s) \n", i, value, selectedValue);
            }

            // clear memory
            cmaes_exit(&evo); /* release memory */
            free(targetValue);
        }

        if (!success) {
            printf("No valid value for %i\n", i);
        }
    }

// open file
    char* tmpFile = concat("../lookupTableTmp", concat(fileName,".c"));
    fileName = concat("../lookupTable", concat(fileName,".c"));

    FILE *file = fopen("../lookupTableArchetype.c", "r+");
    FILE *tmp = fopen(tmpFile, "w");

// move to lookup table
    char c = '.';
    char goal[12] = "lookupTable{";
    int goalPosition = 0;
    while (goalPosition < 12) {
        fscanf(file,
               "%c", &c);
        if (c == goal[goalPosition]) {
            goalPosition++;
        }
        fprintf(tmp,
                "%c", c);
    }

// push new values
    for (
            int i = 0;
            i < table_size;
            i++) {
        if (i > 0) {
            fprintf(tmp,
                    ", ");
        }
        if (i % 10 == 0) {
            fprintf(tmp,
                    "\n");
        }
        fprintf(tmp,
                "%.*e", DECIMAL_DIG, newTable[i]);
    }

// move to after lookup table
    while (c != '}') {
        fscanf(file,
               "%c", &c);
    }
// print rest of file
    while (!
            feof(file)
            ) {
        fprintf(tmp,
                "%c", c);
        fscanf(file,
               "%c", &c);
    }

// close file
    fclose(file);
    fclose(tmp);

// delete old file
    remove(fileName);
    rename(tmpFile, fileName);
    printf("%s", "DONE");

    return 0;
}

