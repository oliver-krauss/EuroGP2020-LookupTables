//
// Created by p40984 on 24.09.19.
//

#include <float.h>
#include <assert.h>
#include <math.h>

#include "lookupTable.h"
#include "newtonianApproximation.h"
#include "userProvidedFunction.h"

// size of range between lookupTable[x] and lookupTable [x+1]
double stepSize;

double searchSpaceScale;

void initFitnessValues() {
    searchSpaceScale = 1E4;
    stepSize = (higher_end - lower_end) / table_size;
}

/**
 * Applies a natural log to the fitness value to transform really small values into bigger ones, preventing cmaes from aborting due to too small changes in the changeset
 */
double lq(double f) {
    double quality = fabs(distanceFromDoublePrecision(f));
    return quality * searchSpaceScale;
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
    return lq(center);
}
