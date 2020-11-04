#include "libmx.h"

void *mx_memrchr (const void *s, int c, size_t n) {
    if (!s)
        return NULL;
    for (size_t i = n-1; i > 0; i--)
        if (((unsigned char *)s)[i] == c)
            return &((unsigned char *)s)[i];
    return NULL;
}
