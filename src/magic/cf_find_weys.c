#include "pathfinder.h"

void cf_find_weys(t_dest_arrs *arrs) {
    for (int j = 0; j < arrs->uniq_island_leng; j++)
        for (int i = 0; i < arrs->uniq_island_leng; i ++)
            for (int k = 0; k < arrs->uniq_island_leng; k++)
                if (arrs->distance[i][k] > arrs->distance[i][j] + arrs->distance[j][k])
                    arrs->distance[i][k] = arrs->distance[i][j] + arrs->distance[j][k];
}
