/**
 * Main function test harness for generated function
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

int main(int argc, char *argv[]) {
    const double input = (argc > 1 && argv[1][0]) ?
                         ((strncmp(argv[1], "0x", 2) == 0) ? read_double(argv[1]) : atof(argv[1])) : 1.0;
    int Digs = DECIMAL_DIG;

    double sum = 0;
    double x;
    for (int j = 0; j < 1000; j++) {
        clock_t t;
        t = clock();
        for (long i = 0; i < 1000000; i++) {
            // we need to add so the compiler doesn't optimize the call away
            x += sqrt(sqrt(input)); // To benchmark something just change this line
        }
        t = clock() - t;
        double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
        sum += time_taken;
        printf("time %.*e\n", Digs, time_taken);
    }
    printf("AVG %.*e\n", Digs, sum); // 1000 repeats * 1.000.000 calls -> 1E9 == nanos so it cancels out
    // we need to print so the compiler doesnt optimize the loop away
    printf("ignore %.*e\n", Digs, x);

    double best = sqrt(input);
    printf("Reversed %.*e\n", Digs, best * best);
    printf("C  Bprc %.*e", Digs, best);
    printf(" Bhex %a\n", best);
    return 0;
}