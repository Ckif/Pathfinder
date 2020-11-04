#include "pathfinder.h"

bool cf_no_file(char *c) {
    if (open(c, O_RDONLY) == -1) {
        mx_printerr("error: file ");
        mx_printerr(c);
        mx_printerr(" does not exist\n");
        return 1;
    }
    return 0;
}
