#include "libmx.h"

long cf_atol(char *c) {
    long result = 0;
    bool sign = false;

    if(*c) {
        while(mx_isspace(*c))
            c++;
        if (*c == '-') {
            sign = true;
            c++;
        }
        else if (*c == '+')
            c++;
        while (mx_isdigit(*c)) {
            result *= 10;
            result += *c-48;
            c++;
        }
        if (sign)
            result = -result;
    }
    return result;
}
