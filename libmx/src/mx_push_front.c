#include "libmx.h"

void mx_push_front(t_list **list, void *data){
    t_list *sec = NULL;;
    
    if((*list) == NULL){
        (*list) = mx_create_node(data);
        return;
    }
    sec = mx_create_node(data);
    sec->next = (*list);
    (*list) = sec;
}
