#include <pathfinder.h>

static bool cf_find_uniq_island(int uniq_island_count, char *str, char **uniq_island) {
    for(int i = 0; i < uniq_island_count; i++)
        if(mx_strcmp(uniq_island[i], str) == 0)
            return false;
    return true;
}
bool cf_invalid_island_count(int arr_count, int island_count,
                             t_dest_arrs *arrs) {
    arrs->uniq_island_leng = 0;

    arrs->uniq_islands = (char **)malloc(sizeof(char*) * (island_count + 1));
    for (int i = 0; i < arr_count ; i++)
        if (mx_isalpha(arrs->island[i][0]))
            if(cf_find_uniq_island(arrs->uniq_island_leng, arrs->island[i],arrs->uniq_islands)) {
                arrs->uniq_islands[arrs->uniq_island_leng] = arrs->island[i];
                arrs->uniq_island_leng++;
            }
    if (arrs->uniq_island_leng != island_count) {
        free(arrs->uniq_islands);
        mx_printerr("error: invalid number of islands\n");
        return true;
    }
    for(int i = 0; i < island_count; i++) {
        arrs->uniq_islands[i] = mx_strdup(arrs->uniq_islands[i]);
    }
    return false;
}

