/**
 * The code that shall be provided by the user
 * @author Oliver Krauss @date 21 Aug 2019
 */

#include <math.h>
#include <stdlib.h>

#include "newtonianApproximation.h"


double fn(const double approx) {
    return approx * approx;
}

double derivativeFn(const double approx) {
    return 2 * approx ;
}

double userFunction(const double x) {
    if (x < 0) return approximate(0.0 - x);
    if (x > 0) return approximate(x);
    return x;
}