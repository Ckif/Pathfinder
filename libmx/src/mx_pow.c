#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0) {
        return 1;
    }
    for (double j = n; pow > 1; pow--) {
        n*=j;
    }
    return n;
}
