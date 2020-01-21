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


void initFitnessValues() {
    stepSize = (higher_end - lower_end) / table_size;
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

    // NOTE value is actually the LOWER END right now. FIX;
    double center = value;

    lookupTable[calcLookupTablePosition(center)] = x[0];

    double quality = fabs(fn(x[0]) - center);

    return quality;
}