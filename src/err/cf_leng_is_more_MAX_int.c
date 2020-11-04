#include "pathfinder.h"
static void err(t_dest_arrs *arrs) {
    mx_printerr("error: sum of bridges lengths is too big\n");
}

bool cf_leng_is_more_MAX_int(int island_arr_count, t_dest_arrs *arrs) {
    size_t test = 0;

    for(int i = 2, j = 0; i < island_arr_count; i += 3, j++) {
        test += cf_atol(arrs->island[i]);
    }
    if (test > INT_MAX) {
        err(arrs);
        return true;
    }
    return false;
}

