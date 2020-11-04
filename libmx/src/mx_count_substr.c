#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int sub_len = 0;

    if (!str || !sub)
        return -1;
    sub_len = mx_strlen(sub);
    while (sub_len <= mx_strlen(str)) {
        if (mx_strstr(str, sub)) {
            str = mx_strstr(str, sub);
            str += sub_len;
            count++;
        }
        else
            return count;
    }
    return count;
}
