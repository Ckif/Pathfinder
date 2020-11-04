#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int j;

    for (j = 0; src[j] != '\0' && j < len; j++)
        dst[j] = src[j];
    return dst;
}
