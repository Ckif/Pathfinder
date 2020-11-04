#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *lol = NULL;

    if (head == NULL || *head == NULL)
        return;
    if (head && *head && (*head)->next){
        lol = *head;
        for (;lol->next->next; lol = lol->next);
        free(lol->next);
        lol->next = NULL;
    }
    else if (head && *head) {
        free(lol->next);
        lol->next = NULL;
    }
}

// void mx_pop_back(t_list **list){
//     t_list *list = *head;

//     if (!(*head))
//         return;
//     if(list->next == NULL){
//         free((*head)->data);
//         return;
//     }
//     while (list->next->next != NULL){
//         head = head->next;
//     }
//     free(head->next->data);
//     head->next = NULL;
// }



// t_list *cur = NULL;
//     if (head && *head && (*head)->next) {
//         cur = *head;
//         while (cur->next->next)
//             cur = cur->next;
//         free(cur->next);
//         cur->next = NULL;
//     } else if (head && *head) {
//         free(*head);
//         *head = NULL;
//     }
// }
