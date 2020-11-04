#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0;
    int check = 0;

    if(!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {      
        if (str[i] == delimiter && check != 0){
            count++;
            check = 0;
        }
        else if (str[i] != delimiter)
            check = 1;
    }
    return count+1;
}
