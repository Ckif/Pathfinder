#include "pathfinder.h"

static inline void all_free(t_dest_arrs *arrs) {
    for(int i = 0; i < arrs->uniq_island_leng; i++) {
        free(arrs->distance[i]);
    }
    for(int i = 0; i < arrs->uniq_island_leng; i++) {
        free(arrs->start_distance[i]);
    }
    mx_del_strarr(&arrs->island);

    mx_del_strarr(&arrs->uniq_islands);
    free(arrs->distance);
    free(arrs->start_distance);
    free(arrs->uniq_islands);
    free(arrs->final_string);
    free(arrs->exit_islands);
    free(arrs->cmp_islands);
    free(arrs);
}


int main (int argc, char **argv) {
    t_dest_arrs *arrs = NULL;

    if (cf_all_errs(argc, argv[1], &arrs))
        exit(0);
    cf_fill_int_matrix(arrs);
    cf_find_weys(arrs);
    cf_return_ways(arrs);
    all_free(arrs);
    exit(0);
}

