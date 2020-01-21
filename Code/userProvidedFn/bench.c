/**
 * Benchmark does 1000 groupings of applying the super root
 * @author Oliver Krauss @date 21 Aug 2019
 */
#define Version "$Revision: 1.0 $"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "helperFunctions.h"
#include "userProvidedFunction.h"
#include "newtonianApproximation.h"

int main(int argc, char *argv[]) {
    const double input = (argc > 1 && argv[1][0]) ?
                         ((strncmp(argv[1], "0x", 2) == 0) ? read_double(argv[1]) : atof(argv[1])) : 1.0;
    int Digs = DECIMAL_DIG;

    /**
     * As the values are INCREDIBLY fast we do NOT want to
     * The Benchmark will become MORE accurate the greater i is in the in the inner loop.
     *   Make sure they don't become less than 1ms (e-4), as otherwise the values become irrelevant measures
     * The timings will be calculated 1000 times to ensure we have a valid mean.
     */
    double sum = 0;
    double x;
    for (int j = 0; j < 1000; j++) {
        clock_t t;
        t = clock();
        for (long i = 0; i < 1000000; i++) {
            // we need to add so the compiler doesn't optimize the call away
            x += userFunction(input);
        }
        t = clock() - t;
        double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
        sum += time_taken;
        printf("time %.*e\n", Digs, time_taken);
    }
    printf("AVG %.*e\n", Digs, sum); // 1000 repeats * 1.000.000 calls -> 1E9 == nanos so it cancels out
    // we need to print so the compiler doesnt optimize the loop away
    printf("ignore %.*e\n", Digs, x);


    double best = userFunction(input);
    printf("Reversed %.*e\n", Digs, fn(best));
    printf("UF  Bprc %.*e", Digs, best);
    printf(" Bhex %a\n", best);

    return 0;
}