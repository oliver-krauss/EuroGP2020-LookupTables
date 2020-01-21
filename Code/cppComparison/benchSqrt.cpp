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
    double sum = 0;
    double x;

    for (int j = 0; j < 1000; j++) {
        clock_t t;
        t = clock();
        for (long i = 0; i < 1000000; i++) {
            x += std::sqrt(input);
        }
        t = clock() - t;
        double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
        sum += time_taken;
        std::cout << "time " << time_taken << std::endl;
    }

    std::cout << "AVG:" << sum << std::endl;  // 1000 repeats * 1.000.000 calls -> 1E9 == nanos so it cancels out
    // we need to print so the compiler doesnt optimize the loop away
    std::cout << "ignore" << x << std::endl;

    double result = std::cbrt(input);
    std::cout << "Reversed:" << result * result << std::endl;

    std::cout << "Value:" << input << std::endl;
    std::cout << "C++ Bprc " << result;
    std::cout << " Bhex " << std::hexfloat << result << std::endl;


    return 0;
}