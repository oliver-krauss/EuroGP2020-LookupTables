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
    searchSpaceScale = fabs(log(DBL_EPSILON));
    stepSize = (higher_end - lower_end) / table_size;
}

/**
 * Applies a natural log to the fitness value to transform really small values into bigger ones, preventing cmaes from aborting due to too small changes in the changeset
 */
double lq(double f) {
    double quality = fabs(distanceFromDoublePrecision(f));
    if (quality >= 1) {
        return quality + searchSpaceScale;
    } else if (quality == 0.0) {
        return 0;
    }
    quality = log(quality) + searchSpaceScale;

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

    double lower = value - stepSize / 3;
    double center = value;
    double upper = value + stepSize / 3;

    lookupTable[calcLookupTablePosition(center)] = x[0];
    return lq(lower) + lq(center) + lq(upper);
}
