//
// Interface for the fintess function so we can test different fns by including different files
// Created by Oliver Krauss on 24.09.19.
//

#ifndef USERPROVIDEDFN_FITFUN_H
#define USERPROVIDEDFN_FITFUN_H

double fitfun(double const *x, int dim, double value);

/**
 * MUST be called before the fitness function is used
 */
void initFitnessValues();

#endif //USERPROVIDEDFN_FITFUN_H
