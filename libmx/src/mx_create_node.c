#include "libmx.h"


t_list *mx_create_node(void *data){
    t_list *first = NULL;

    first = (t_list*)malloc(sizeof(t_list));
    first->data = data;
    first->next = NULL;
    return first;
}
