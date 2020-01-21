/**
 * The code that shall be provided by the user
 * @author Oliver Krauss @date 21 Aug 2019
 */

#include <math.h>
#include <stdlib.h>

#include "newtonianApproximation.h"


double fn(const double approx) {
    //27x^3−3x+1
    return 27 * approx * approx * approx - 3 * approx + 1;
}

double derivativeFn(const double approx) {
    // 81x2−3
    return 81 * approx * approx - 3;
}

double userFunction(const double x) {
    if (x < 0) return approximate(0.0 - x);
    if (x > 0) return approximate(x);
    return x;
}