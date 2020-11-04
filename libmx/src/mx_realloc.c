#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t size_ptr = malloc_size(ptr);
    void *sub = "\0";

    if ((int)size < 0)
        return NULL;
    if (size == 0) {
        sub = malloc(size);
        free (ptr);
        return sub;
    }
    if(size_ptr > size)
        return ptr;
    sub = malloc(size);
    sub = mx_memcpy(sub, ptr, size);
    return sub;
}

