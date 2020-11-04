#include "libmx.h"

static void cf_swap_list(t_list *buf){
    void *buff = buf->data;
    buf->data = buf->next->data;
    buf->next->data = buff;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *buff = lst;
    bool flag = true;

    while (flag) {
        flag = false;
        while (buff->next)
            if (cmp(buff->data, buff->next->data)) {
                cf_swap_list(buff);
                flag = true;
            } else
                buff = buff->next;
        buff = lst;
    }
    return lst;
}
