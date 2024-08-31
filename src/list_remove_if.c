#include "test.h"

int g_ff_access = 0;

void   _fake_free(void* a)
{
    g_ff_access++;
    (void)a;
}

int _cmp_equ(void* a, void* b)
{
    if ((uint64_t)a == (uint64_t)b)
        return (0);
    return (1);
}

int _cmp_mod(void* a, void* b)
{
    if ((uint64_t)a % (uint64_t)b == 0)
        return (0);
    return (1);
}

/*
Create the function ft_list_remove_if which removes from the list,
 all elements
whose data compared to data_ref using cmp, makes cmp return 0.
• The data from an element to be erased should be freed using 
free_fc
Function pointed by cmp and by free_fct will be used as follows :
    (*cmp)(list_ptr->data, data_ref);
    (*free_fct)(list_ptr->data);
*/
void    list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list* current = NULL;
    t_list* parent  = *begin_list;

    while (parent)
    {
        if ((*cmp)(parent->data, data_ref) == 0)
        {
            *begin_list = parent->next;
            (*free_fct)(parent->data);
            free(parent);
            parent = *begin_list;
        }
        else
        {
            current = parent->next;
            break ;
        }
    }

    while (current)
    {
        if ((*cmp)(current->data, data_ref) == 0)
        {
            parent->next = current->next;
            (*free_fct)(current->data);
            free(current);
        }
        else
            parent = current;
        current = parent->next;
    }
}


int    list_check_if(t_list *head, void *data_ref, int (*cmp)())
{
    while(head)
    {
        if ((*cmp)(head->data, data_ref) == 0)
            return (1);
        head = head->next;
    }
    return (0);
}

void    list_remove_if_wrapper(void* data_ref, int (*cmp)(), void (*free_fct)(void *), int expected_ff)
{
    t_list  *lst = NULL;

    g_ff_access = 0;
    for(uint64_t i = 0; i < 21; i++)
    {
        list_push_front(&lst, (void*)i);
    }
    // printf("\n");
    // list_print(lst);
    ft_list_remove_if(&lst, data_ref, cmp, free_fct);
    // list_print(lst);
    check(list_check_if(lst, data_ref, cmp) == 0);
    check(g_ff_access == expected_ff);
    listclear(&lst);
}

void    list_remove_if_tester(void)
{
    printf("list_remove_if:\t");
    list_remove_if_wrapper((void*)51, _cmp_equ, _fake_free, 0);
    list_remove_if_wrapper((void*)7, _cmp_equ, _fake_free, 1);
    list_remove_if_wrapper((void*)1, _cmp_mod, _fake_free, 21);
    list_remove_if_wrapper((void*)2, _cmp_mod, _fake_free, 11);
    list_remove_if_wrapper((void*)5, _cmp_mod, _fake_free, 5);
    printf("\n");
}

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    list_remove_if_tester();
}
