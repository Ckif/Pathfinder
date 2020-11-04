#include "libmx.h"

char *mx_itoa(int number) {
    int i = 0;
    char *c = NULL;

    if (number == -2147483648)
        return "-2147483648";
    if (number == 0)
        return "0";
    for (int j = number ; j != 0; i++, j/=10);
    if (number < 0) {
        number*=-1;
        i++;
        c = mx_strnew(i);
        c[0] = '-';
    }
    else 
        c = mx_strnew(i);
    for (; number > 0; i--, c[i] = number%10+48, number/=10);
    return c;
}
