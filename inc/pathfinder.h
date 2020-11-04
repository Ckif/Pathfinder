#pragma once

#include "../libmx/inc/libmx.h"
#include <limits.h>

typedef struct s_dest_arr {
    int uniq_island_leng;
    int island_arr_count;
    int final_substring;
    int exit_distance_long;
    int varios;
    int int_arrs_count;
    int *exit_islands;
    int **cmp_islands;
    char **island;
    char **uniq_islands;
    char **final_string;
    char **leng_string;
    long **start_distance;
    long **distance;
}              t_dest_arrs;

                        //Error LIB
bool cf_all_errs(int i, char *c, t_dest_arrs **arrs);
bool cf_no_filename (int i);
bool cf_no_file(char *c);
bool cf_file_is_empty(char *c, char *buff);
bool cf_invalid_fline(int *island_count, int fline, char *buff);
bool cf_wrong_char (int fline, char *buff);
bool cf_invalid_island_count(int arr_count, int island_count, t_dest_arrs *arrs);
bool cf_duble_line(int island_arr_count, char **str);
bool cf_leng_is_more_MAX_int (int island_arr_count, t_dest_arrs *arrs);
                        //Magic LIB
void cf_fill_int_matrix(t_dest_arrs *arrs);
void cf_find_weys(t_dest_arrs *arrs);
void cf_return_ways (t_dest_arrs *arrs);
bool cf_cmpint(int *s1, int *s2);
