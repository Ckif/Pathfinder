#include "pathfinder.h"

static bool cf_test_1(char *c, char *buff, int *island_count, int fline) {
    if (cf_file_is_empty(c, buff) || cf_invalid_fline(island_count, fline, buff) ||
        cf_wrong_char(fline, buff)) {
        mx_strdel(&buff);
        return true;
    }
    return false;
}
static bool cf_test_2(int buff_long, int island_count, char **buff, t_dest_arrs *arrs) {
    int island_arr_count = 0;

    for (; arrs->island[island_arr_count] != NULL; island_arr_count++);
    if (cf_invalid_island_count(island_arr_count, island_count, arrs) ||
        cf_duble_line(island_arr_count, arrs->island) ||
        cf_leng_is_more_MAX_int (island_arr_count, arrs)) {
        free(*buff);
        return true;
    }
    return false;
}
static void cf_buff_manip(int *fline, int *buff_long, char *buff) {
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' || buff[i] == ',') {
            buff[i] = '-';
        }
    }
    for(int i = 0; i <= *fline; i++)
        buff[i] = '-';
    *buff_long = mx_strlen(buff);
}

bool cf_all_errs(int i, char *c, t_dest_arrs **arrs) {
    char *buff = NULL;
    int fline = 0;
    int island_count = 0;
    int buff_long = 0;

    if (cf_no_filename(i) || cf_no_file(c))
        return true;
    buff = mx_file_to_str(c);
    for (; buff[fline] != '\n'; fline++);
    if (cf_test_1(c, buff, &island_count, fline))
        return true;
    cf_buff_manip(&fline, &buff_long, buff);
    *arrs = (t_dest_arrs *)malloc(sizeof(t_dest_arrs));
    (*arrs)->island = mx_strsplit(buff, '-');
    if (cf_test_2(buff_long, island_count, &buff, *arrs))
        return true;
    free(buff);
    return false;
}

