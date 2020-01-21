#include <iostream>
#include <string.h>
#include <math.h>
#include <float.h>


double read_double(const char *text) {
    int val = atof(text);
    return val;
}

int main(int argc, char **argv) {
    const double input = (argc > 1 && argv[1][0]) ?
                         ((strncmp(argv[1], "0x", 2) == 0) ? read_double(argv[1]) : atof(argv[1])) : 1.0;
    std::cout.precision(DECIMAL_DIG);

    double result = std::cbrt(input);

    std::cout << "Reversed:" << result * result * result << std::endl;

    std::cout << "Value:" << input << std::endl;
    std::cout << "C++ Bprc " << result;
    std::cout << " Bhex " << std::hexfloat << result << std::endl;


    return 0;
}