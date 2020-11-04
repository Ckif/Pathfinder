#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int len = 0;

    if (!s1)
        len = 0;
    else
        len = mx_strlen(s1);
    for (int i = len, j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
    s1[len + mx_strlen(s2)] = '\0';
    return s1;
}
