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

#include "helperFunctions.h"

int main(int argc, char *argv[]) {
    const double input = (argc > 1 && argv[1][0]) ?
                         ((strncmp(argv[1], "0x", 2) == 0) ? read_double(argv[1]) : atof(argv[1])) : 1.0;
    double best = sqrt(sqrt(input));
    int Digs = DECIMAL_DIG;

    printf("Reversed %.*e\n", Digs, best * best * best * best);
    printf("C  Bprc %.*e", Digs, best);
    printf(" Bhex %a\n", best);


    return 0;
}