#include "libmx.h"

void mx_pop_front(t_list **head){
//     t_list *def = NULL;

//     if (!(*head))
//         return;
//     if ((*head)->next == NULL){
//         free(*head);
//         return;
//     }
//     if ((*head)->next != NULL){
//         def = *head;
//         free(*head);
//         *head = def;
//     }
// }

    t_list *next_node = NULL;
    if (head && *head) {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }
}

//     t_list *head = *list;
//     if (!(*list))
//         return;
//     if(head->data == NULL){
//         free((*list)->data);
//         return;
//     }
//     if(head->next != NULL){
//         (*list) = head->next;
//         free(head->data);
//     }
//     head->data = NULL;
// }
