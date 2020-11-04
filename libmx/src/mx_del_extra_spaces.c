#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *trimmed_str = mx_strtrim(str);
    char *no_extra_sp = NULL;
    int count = 0;

    if (!str)
        return NULL;
    for (int i = 0; trimmed_str[i] != '\0'; i++) {
        if (mx_isspace(trimmed_str[i]) == 1 && 
            mx_isspace(trimmed_str[i+1]) == 1);
        else {
            trimmed_str[count] = trimmed_str[i];
            count++;
        }
    }
    no_extra_sp = mx_strndup(trimmed_str, count);
    mx_strdel(&trimmed_str);
    return no_extra_sp;
}
