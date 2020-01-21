/**
 * The newtonian approximation using userProvidedFunction.c
 * as well as the table provided by CMA-ES
 * @author Oliver Krauss @date 21 Aug 2019
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <values.h>
#include "userProvidedFunction.h"
#include "lookupTable.h"

// amount of newtonian approximation iterations to be done with value from lookup table
const int iterations = 3;

int calcLookupTablePosition(double val) {
//    if (val < lower_end || val > higher_end) {
//        exit(1);
//    }
    double stepSize = (higher_end - lower_end) / table_size;
    double position = (val - lower_end) / stepSize;

    int tablePosition = position;
    if (tablePosition <= -1) {
        tablePosition = 0;
    }
    if (tablePosition >= table_size) {
        tablePosition = table_size - 1;
    }
    return tablePosition;
}

double approximate(const double val) {
    // find correct entry point in lookup table
    int tablePosition = calcLookupTablePosition(val);

    // initialize from table
    double result = lookupTable[tablePosition]; // NOTE: this will FAIL while lookupTable was not initialized
    double h;

    // check range
    if (val < lower_end) {
        printf("Value too small for generated lookup\n");
    }
    if (val > higher_end) {
        printf("Value too large for generated lookup\n");
    }

    for (int i = 0; i < iterations; i++) {
        h = (fn(result) - val) / derivativeFn(result);

        // x(i+1) = x(i) - f(x) / f'(x)
        result = result - h;
    }

    return result;
}

double distanceFromDoublePrecision(const double val) {
    // find correct entry point in lookup table
    int tablePosition = calcLookupTablePosition(val);

    // initialize from table
    double result = lookupTable[tablePosition]; // NOTE: this will FAIL while lookupTable was not initialized
    double h;

    // check range
    if (val < lower_end) {
        printf("Value too small for generated lookup\n");
    }
    if (val > higher_end) {
        printf("Value too large for generated lookup\n");
    }

    for (int i = 0; i < iterations; i++) {
        h = (fn(result) - val) / derivativeFn(result);

        // x(i+1) = x(i) - f(x) / f'(x)
        result = result - h;
    }

    return h;
}
