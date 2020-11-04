#include "pathfinder.h"

bool cf_no_filename (int i) {
    if (i == 1) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    return 0;
}
