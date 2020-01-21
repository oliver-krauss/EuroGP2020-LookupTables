//
// Created by p40984 on 21.08.19.
//

#ifndef USERPROVIDEDFN_NEWTONIANAPPROXIMATION_H
#define USERPROVIDEDFN_NEWTONIANAPPROXIMATION_H

/**
 * Uses Newton Raphson to approximate fn(val)/dFn(val) initialized with lookupTable.c
 * @param val value to approximate fn of
 * @return approximated value
 */
double approximate(const double val);

/**
 * Instead of returning the approximation of the requested value, remaining error is returned
 * @param val of which we want to know the precision
 * @return error left to actual solution
 */
double distanceFromDoublePrecision(double val);

/**
 * Boolean check if we reached double precision (convenience function)
 * @param val to check
 * @return if it is precise
 */
int isDoublePrecision(double val);

int calcLookupTablePosition(double val);

#endif //USERPROVIDEDFN_NEWTONIANAPPROXIMATION_H
