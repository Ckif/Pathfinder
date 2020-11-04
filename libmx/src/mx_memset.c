#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    for (size_t i = 0; i < len; i++) //size_t - это получается просто unsigned long int?
        ((unsigned char *)b)[i] = c; //почему каст?
    return b;
}
