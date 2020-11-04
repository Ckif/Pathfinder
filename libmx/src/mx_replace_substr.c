#include"libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *rezult = NULL;
    char *buff = NULL;
    int sub_len = 0;
    int replace_len = 0;
    int counter = 0;

    if (!str || !sub || !replace)
        return NULL;
    sub_len = mx_strlen(sub);
    replace_len = mx_strlen(replace);
    rezult = mx_strnew(mx_strlen(str));
    buff = mx_strnew(sub_len);
    for (int i = 0; str[i] != '\0';) {
        if (str[i] == sub[0]) {
            for(int j = 0; j < sub_len; j++)
                buff[j] = str[j+i];
            if (mx_strcmp(buff, sub) == 0) {
                for (int j = 0; j < replace_len; j++)
                    rezult[counter+j] = replace[j];
                i += sub_len;
                counter += replace_len;
            }
        }
        else {
            rezult[counter] = str[i];
            i++;
            counter++;
        }
    }
    mx_strdel(&buff);
    buff = mx_strdup(rezult);
    mx_strdel(&rezult);
    return buff;
}
