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
#include "userProvidedFunction.h"
#include "newtonianApproximation.h"

int main(int argc, char *argv[]) {
    const double input = (argc > 1 && argv[1][0]) ?
                         ((strncmp(argv[1], "0x", 2) == 0) ? read_double(argv[1]) : atof(argv[1])) : 1.0;
    double best = userFunction(input);
    int Digs = DECIMAL_DIG;

    printf("Reversed %.*e\n", Digs, fn(best));
    printf("UF  Bprc %.*e", Digs, best);
    printf(" Bhex %a\n", best);


    // check if we are perfect or only ONE bit off -X as double doesnt allow bit additions we cheat with long
    if (fn(best) == input) {
        printf("Perfect Result");
    } else {
        long lower;
        long higher;
        double lowerBest = 0;
        double higherBest = 0;

        memcpy(&lower, &best, sizeof(best));
        memcpy(&higher, &best, sizeof(best));
        lower = lower - 1;
        higher = higher + 1;
        memcpy(&lowerBest, &lower, sizeof(lower));
        memcpy(&higherBest, &higher, sizeof(higher));

        double errBest = fabs(fn(best) -input);
        double errLower = fabs(fn(lowerBest) -input);
        double errHigher = fabs(fn(higherBest) -input);

        if (errBest <= errLower && errBest <= errHigher)
        {
            printf("Perfect Result");
        }
    }


    return 0;
}