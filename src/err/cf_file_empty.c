#include "pathfinder.h"

bool cf_file_is_empty(char *c, char *buff) {
    if (read(open(c, O_RDONLY), buff, 1) == 0) {
        mx_printerr("error: file ");
        mx_printerr(c);
        mx_printerr(" is empty\n");
        return 1;
    }
    return 0;
}

