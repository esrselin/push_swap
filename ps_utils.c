//Eleman ekleme
#include <stdlib.h>
#include "push_swap.h"
t_list *add_node(int data)
{
    t_list *tmp;
    tmp = malloc(sizeof(t_list));
    if(!tmp)
        return NULL;
    tmp->data = data;
    tmp->next = NULL;

    return tmp;
};
void add_front(t_list **head, t_list *new)
{
    if (!head || !new)
        return;
    new->next = *head;
    *head = new;
}
void add_back(t_list **head, t_list *new)
{
    t_list *cur;

        if (!head || !new)
        return;
    if (!*head)
    {
        *head = new;
        return;
    }
    cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

int list_size(t_list *node)
{
    int i;
    i = 0;
    while(node != NULL)
    {
        i++;
        node = node->next;
    }
    return (i);
}