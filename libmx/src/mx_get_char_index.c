#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str)
        return -2;
    for (int rezult = 0; rezult < mx_strlen(str); rezult++) {
        if(str[rezult] == c)
            return rezult;
    }
    return -1;
}
