#include "_list_push_front.h"

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