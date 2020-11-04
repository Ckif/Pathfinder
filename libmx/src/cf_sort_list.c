#include "libmx.h"

bool cf_sort_list(void *a, void *b) {
    if (a > b)
        return true;
    return false;
}
