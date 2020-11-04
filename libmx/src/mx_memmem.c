#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
                const void *little, size_t little_len) {
    if (!big || !little)
        return NULL;
    for (size_t i = 0, j; i < big_len; i++)
        if (((unsigned char *) big)[i] == ((unsigned char *)little)[0]) {
            for (j = 0; ((unsigned char *)big)[i+j] == 
                               ((unsigned char *)little)[j] 
                               && j < little_len; j++);
            if (j == little_len)
                return &((unsigned char *) big)[i];
        }
    return NULL;
}
