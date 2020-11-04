#include "pathfinder.h"

static inline void memory_allocate (t_dest_arrs *arrs) {
    arrs->start_distance = (long **)malloc(sizeof(long *) * (arrs->uniq_island_leng));
    arrs->distance = (long **)malloc(sizeof(long *) * (arrs->uniq_island_leng));
    for(int i = 0; i < arrs->uniq_island_leng; i++) {
        arrs->distance[i] = (long *) malloc(sizeof(long) * arrs->uniq_island_leng);
        arrs->start_distance[i] = (long *) malloc(sizeof(long) * arrs->uniq_island_leng);
    }
}

void cf_fill_int_matrix(t_dest_arrs *arrs) {
    memory_allocate(arrs);
    for(int j = 0; j < arrs->uniq_island_leng; j++)
        for(int k = 0; k < arrs->uniq_island_leng; k++) {
            for (int i = 0; arrs->island[i] != NULL; i += 3)
                if (mx_strcmp(arrs->uniq_islands[j], arrs->island[i]) == 0)
                    if (mx_strcmp(arrs->uniq_islands[k], arrs->island[i + 1]) == 0) {
                        arrs->distance[j][k] = cf_atoi(arrs->island[i + 2]);
                        arrs->distance[k][j] = arrs->distance[j][k];
                        arrs->start_distance[j][k] = arrs->distance[j][k];
                        arrs->start_distance[k][j] = arrs->distance[j][k];
                    }
            if (arrs->distance[j][k] == 0 && j != k){
                arrs->distance[j][k] = INT_MAX;
                arrs->distance[k][j] = arrs->distance[j][k];
            }
        }
}
