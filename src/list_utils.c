#include "tests.h"

void	_listclear(t_list **list)
{
    t_list  *buff;

    if (!list)
        return ;
    while (*list)
    {
        buff = (*list)->next;
        free(*list);
        *list = buff;
    }
    list = NULL;
}

static t_list *create_elem(void *data)
{
    t_list	*new = malloc(sizeof(t_list));

    if (new)
    {
        new->data = data;
        new->next = NULL;
    }
    return (new);
}

void    _list_push_front(t_list **begin_list, void *data)
{
    t_list* new = create_elem(data);

    if (!new)
        return ;
    if (*begin_list)
        new->next = *begin_list;
    *begin_list = new;
}
