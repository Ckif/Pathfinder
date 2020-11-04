#include "pathfinder.h"

static inline void cf_print_path (int j, int i, t_dest_arrs *arrs) {
    for (int k = 0; k <= arrs->int_arrs_count; k++) {
        for (int l = 0; arrs->cmp_islands[k][l] != -1; l++) {
            if (arrs->cmp_islands[k][l] == j) {
                mx_printstr("========================================\nPath: ");
                mx_printstr(arrs->uniq_islands[j]);
                mx_printstr(" -> ");
                mx_printstr(arrs->uniq_islands[i]);
                mx_printstr("\nRoute: ");
                mx_printstr(arrs->uniq_islands[j]);
                mx_printstr(" -> ");
            } else if (arrs->cmp_islands[k][l] == i) {
                mx_printstr(arrs->uniq_islands[i]);
                mx_printstr("\nDistance: ");
                if (l <= 1)
                    mx_printint(arrs->distance[j][i]);
                else {
                    for (int g = 0; arrs->cmp_islands[k][g + 1] != -1; g++) {
                        if (g > 0)
                            mx_printstr(" + ");
                        mx_printint(arrs->distance[arrs->cmp_islands[k][g]][arrs->cmp_islands[k][g + 1]]);
                    }
                    mx_printstr(" = ");
                    mx_printint(arrs->distance[j][i]);
                }
                mx_printstr("\n========================================\n");
            } else if (arrs->cmp_islands[k][l] != -1) {
                mx_printstr(arrs->uniq_islands[arrs->cmp_islands[k][l]]);
                mx_printstr(" -> ");
            }
        }
//        if (arrs->cmp_islands[k])
//            free(arrs->cmp_islands[k]);
    }
}


static void way(int j, int i, t_dest_arrs *arrs) {
    for (int l = 0; l < arrs->final_substring; l++) {
        if (arrs->exit_islands[l] == j) {
            l++;
            for (; arrs->exit_islands[l] != i; l++);
        }
        else
            arrs->exit_islands[l] = -1;
    }
    for (int l = arrs->final_substring; l > 0; l--) {
        if (arrs->exit_islands[l] == i) {
            l--;
            for (; arrs->exit_islands[l] != j; l--);
        }
        else
            arrs->exit_islands[l] = -1;
    }
    arrs->int_arrs_count = -1;
    for (int l = 0, m = 0; l < arrs->final_substring; l++) {
        if (arrs->exit_islands[l] == j) {
            m = 0;
            arrs->int_arrs_count++;
            arrs->cmp_islands[arrs->int_arrs_count] = malloc(sizeof(int) * arrs->final_substring);
            for (int h = 0; h <= arrs->final_substring; arrs->cmp_islands[arrs->int_arrs_count][h] = -1, h++);
            for (; arrs->exit_islands[l] != i; l++, m++)
                    arrs->cmp_islands[arrs->int_arrs_count][m] = arrs->exit_islands[l];
            arrs->cmp_islands[arrs->int_arrs_count][m] = arrs->exit_islands[l];
        }
    }
    if (arrs->int_arrs_count > 0)
        for (int k = 0; k < arrs->int_arrs_count; k++)
            for (int l = k + 1; l <= arrs->int_arrs_count; l++)
                    cf_cmpint(arrs->cmp_islands[k], arrs->cmp_islands[l]);
    cf_print_path(j, i, arrs);
}
static void cf_start_correct_way(int j, int i, t_dest_arrs *arrs){
    if (arrs->final_substring > 0) {
        if (arrs->exit_islands[arrs->final_substring - 1] == j) {
            arrs->exit_islands[arrs->final_substring] = i;
            arrs->final_substring++;
        }
        else {
            arrs->exit_islands[arrs->final_substring] = j;
            arrs->exit_islands[arrs->final_substring + 1] = i;
            arrs->final_substring += 2;
        }
    }
    else {
        arrs->exit_islands[arrs->final_substring] = j;
        arrs->exit_islands[arrs->final_substring + 1] = i;
        arrs->final_substring += 2;
    }
}

static void subway (int j, int i, t_dest_arrs *arrs) {
    for (int k = 0; k < arrs->uniq_island_leng; k++) {
        if (arrs->distance[j][k] != 0 && j != i) {
            if (arrs->distance[j][i] - arrs->distance[j][k] != 0) {
                if (arrs->distance[j][i] == arrs->distance[j][k] + arrs->distance[k][i]) {
                    if (arrs->distance[j][k] != arrs->start_distance[j][k])
                        subway(j, k, arrs);
                    else if (arrs->distance[j][k] == arrs->start_distance[j][k])
                        cf_start_correct_way(j, k, arrs);
                    if (arrs->distance[k][i] != arrs->start_distance[k][i])
                        subway(k, i, arrs);
                    else if (arrs->distance[k][i] == arrs->start_distance[k][i])
                        cf_start_correct_way(k, i, arrs);
                }
            }
        } else if (arrs->distance[j][i] == arrs->start_distance[j][i])
            cf_start_correct_way(j, i, arrs);
    }
}

void cf_return_ways (t_dest_arrs *arrs) {
    arrs->varios = 0;
    arrs->final_substring = 0;

    for (int i = arrs->uniq_island_leng; i > 0; arrs->varios += i, i-- );
    arrs->exit_islands = (int *)malloc(sizeof(int) * arrs->varios);
    arrs->cmp_islands = (int **)malloc(sizeof(int *) * 1000);
    for (int j = 0; j < arrs->uniq_island_leng; j++) { // j откуда
        for(int i = j + 1; i < arrs->uniq_island_leng; i++) { // i куда
                        subway(j, i, arrs);
                        way(j, i, arrs);
                        for (int k = 0; k < arrs->final_substring; k++ )
                            arrs->exit_islands[k] = -1;
                        arrs->final_substring = 0;
        }
    }
}
