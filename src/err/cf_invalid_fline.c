#include "pathfinder.h"

static void err_massage (char *a) {
    mx_printerr("error: line 1 is not valid");
    mx_printerr("\n");
    free (a);
}

bool cf_invalid_fline(int *island_count, int fline, char *buff) {
    char *fl = NULL;
    long test = 0;

    fl = mx_strndup(buff, fline);
    for (int i = 0; fl[i] != '\0'; i++)
        if (!mx_isdigit(fl[i])){
            err_massage (fl);
            return 1;
        }
    test = cf_atol(fl);
    if (test <= 0 || test > INT_MAX) {
        err_massage (fl);
        return 1;
    }
    *island_count = (int)test;
    free(fl);
    return 0;
}
