#include "libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;

    if(!list)
        return 0;
    for (count = 0; list; count++)
        list = list->next;
    return count;
}
