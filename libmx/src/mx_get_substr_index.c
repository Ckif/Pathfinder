#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
     int index = 0;
     int check = 0;

    if (!str || !sub)
        return -2;
    for (; mx_strlen(str) >= index; index++) {
        if (str[index] == sub[0]) {
            for (; str[check+index] == sub[check]; check++);
            if (check == mx_strlen(sub))
                return index;
            else
                check = 0;
        }
    }
    return -1;
}
