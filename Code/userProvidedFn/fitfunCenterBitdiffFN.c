//
// Created by p40984 on 24.09.19.
//

#include <float.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "lookupTable.h"
#include "newtonianApproximation.h"
#include "userProvidedFunction.h"

// size of range between lookupTable[x] and lookupTable [x+1]
double stepSize;

void initFitnessValues() {
    stepSize = (higher_end - lower_end) / table_size;
}

/**
 * Applies a natural log to the fitness value to transform really small values into bigger ones, preventing cmaes from aborting due to too small changes in the changeset
 */
double lq(double f, double value) {
    double quality = fn(f);
    quality = fabs(quality - value);

    if (quality == 0.0) {
        return 0;
    }

    // transform into long (bitwise) and back into double the fewer bits are wrong the closer we get to 0
    long qualifier;
    memcpy(&qualifier, &quality, sizeof(qualifier));
    quality = (double) qualifier;

    return quality;
}

/**
 * Fitness function that evaluates the quality of our solutions
 * @param x     value to be evaluated
 * @param dim   amount of values in X (should always be 1 for us)
 * @param value the original value we wanted to find a solution for
 * @return    closeness to the provided function
 */
double fitfun(double const *x, int dim, double value) {
    assert(dim == 1);

    double center = value;

    lookupTable[calcLookupTablePosition(center)] = x[0];
    return lq(x[0], value);
}
