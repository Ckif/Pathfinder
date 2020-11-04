#include<pathfinder.h>

static void cf_swap_arrs(char **rstr_1, char **rstr_2) {
    char *buff = *rstr_1;

    *rstr_1 = *rstr_2;
    *rstr_2 = buff;
}
static void err2(int i) {
    char *lines = mx_itoa(i);

    mx_printerr("error: line ");
    mx_printerr(lines);
    mx_printerr(" is not valid\n");
    free(lines);
}
static bool cf_cmp_string(int island_arr_count, char **rstr) {
    for (int i = 0, j = 0; i < island_arr_count; i += 3, j = 0) {
        j = mx_strcmp(rstr[i], rstr[i + 1]);
        if (j == 0) {
            err2(i/3 + 1);
            return true;
        }
        if (j > 0)
            cf_swap_arrs(&rstr[i], &rstr[i + 1]);
    }
    return false;
}

bool cf_duble_line(int island_arr_count,char **str) {
    char **rstr = str;

    for(int i = 2, j = 2; i < island_arr_count; i += 3, j++)
        if (mx_strlen(str[i]) > 10 || (mx_strlen(str[i]) == 10 &&
                                       mx_strcmp(str[i], "2147483647") > 0)) {
            err2(j);
            return true;
        }
    if(cf_cmp_string(island_arr_count, rstr))
        return true;
    for (int i = 0; i <= island_arr_count - 6; i += 3) {
        for (int j = i; j <= island_arr_count -6; j+=3) {
            if (mx_strcmp(rstr[i], rstr[j + 3]) == 0)
                if (mx_strcmp(rstr[i + 1], rstr[j + 4]) == 0) {
                    mx_printerr("error: duplicate bridges\n");
                    return true;
                }
        }
    }
    return false;
}
