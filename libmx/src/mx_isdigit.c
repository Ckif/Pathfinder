#include "libmx.h"

bool mx_isdigit(int c) {
    if (c <= 57 && c >= 48)
        return true;
    else
        return false;
}
