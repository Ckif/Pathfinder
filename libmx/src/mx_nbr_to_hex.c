#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char cbuff[100];
    char *result = NULL;
    long rem, temp = nbr;
    int i = 0;
    
    while (temp != 0) {
        rem = temp % 16;
        if (rem < 10)
            cbuff[i++] = 48 + rem;
        else
            cbuff[i++] = 87 + rem;
        temp = temp / 16;
    }

    result = mx_strnew(i);
     for(int j = 0; i > 0; i--, j++)
        result[j] = cbuff[i-1];
    return result;
}
