#include "test.h"

extern int g_verbose;

// general
void    check(char* prefix, bool e)
{
    if (g_verbose == 0)
        prefix = "";
    if (e)
        printf(GREEN"%sOK "END, prefix);
    else
        printf(RED"%sKO "END, prefix);
}

void    fatal(const char * str)
{
    printf("FATAL: %s\n", str);
    exit(1);
}

void    sigsegv_handler(int sig)
{
    (void)sig;
    printf(BOLD""RED" [SIGSEV]\n"END);
    exit(1);
}

// list 
t_list *create_elem(void *data)
{
    t_list	*new = malloc(sizeof(t_list));

    if (new)
    {
        new->data = data;
        new->next = NULL;
    }
    return (new);
}

void    list_push_front(t_list **begin_list, void *data)
{
    t_list* new = create_elem(data);

    if (!new)
        return fatal("malloc failed in list_push_front");
    if (*begin_list)
        new->next = *begin_list;
    *begin_list = new;
}


void	listclear(t_list **list)
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


void    list_print(t_list* list)
{
    while (list)
    {
        printf("%lu ", (uint64_t)list->data);
        list = list->next;
    }
    printf("\n");
}

