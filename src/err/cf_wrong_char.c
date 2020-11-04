#include "pathfinder.h"

static bool bridge_check (char *buf_line, char del, int count, int line) {
    char *lines = mx_itoa(line);

    if (buf_line[count] != del) {
        mx_printerr("error: line ");
        mx_printerr(lines);
        mx_printerr(" is not valid\n");
        free(lines);
        return true;
    }
    free(lines);
    return false;
}

bool cf_wrong_char (int fline, char *buff) {
    for (int count = fline, line = 2; buff[count+1]; line++) {
        for(count = count + 1; mx_isalpha(buff[count]); count++); // первый остров
        if (bridge_check(buff, '-', count, line))
            return true;
        for(count = count + 1; mx_isalpha(buff[count]); count++); // второй остров
        if(bridge_check(buff, ',', count, line))
            return true;
        for(count = count + 1; mx_isdigit(buff[count]); count++); // расстояние между островами
        if (bridge_check(buff, '\n', count, line))
            return true;
    }
return false;
}
