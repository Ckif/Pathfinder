#include "libmx.h"

void cf_intdel(int **str) {
    if (str && *str) {
        free(*str);
//        *str = NULL;
    }
}
