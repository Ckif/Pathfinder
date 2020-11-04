#include "libmx.h"


void mx_push_back(t_list **list, void *data){
    t_list *head = NULL;

    if(NULL == (*list)){
        (*list) = mx_create_node(data);
        return;
    }
    head = (*list);
    while (head->next){
        head = head->next;
    }
    head->next = mx_create_node(data);
}

//     t_list * new_node = (t_list*)malloc(sizeof(t_list));
//     t_list * last = *list;
//     new_node->data = data;
//     new_node->next = NULL;

//     if (*list == NULL) {
//         *list = new_node;
//         return;
//     }

//     while (last->next != NULL)
//         last = last->next;

//     last->next = new_node;
// }



//     t_list *back = mx_create_node(data);
//     t_list *tmp = *list;

//     if (*list == NULL || list == NULL) {
//         *list = back;
//         return;
//     }
//     while (tmp->next != NULL)
//         tmp = tmp->next;
//     tmp->next = back;
// }
