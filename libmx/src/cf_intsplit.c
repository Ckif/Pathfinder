#include"libmx.h"

int **cf_intsplit(char const *s, char c) {
    int words = 0;
    int **ret = NULL;
    char *buff = NULL;

    if (!s)
        return NULL;
    words = mx_count_words(s,c);
    ret = (int **)malloc(sizeof(int *) * (words));
    for (int i = 0, count = 0; i < words-1; i++) {
        count = 0;
        while(*s == c)
            s++;
        while(s[count] != c)
            count++;
        ret[i] = (int *)malloc(sizeof(int));
        buff = mx_strncpy(buff, s, count);
        *ret[i] = cf_atoi(buff);
        buff = NULL;
        s += count;
    }
    // ret[words-1] = NULL;
    return ret;
}
