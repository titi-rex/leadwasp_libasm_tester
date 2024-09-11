#include "test.h"

int g_verbose   = 0;
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
    static int  i = 0;
    t_list  *lst = NULL;

    printf("%d.", i++);

    g_ff_access = 0;
    for(uint64_t i = 0; i < 21; i++)
    {
        list_push_front(&lst, (void*)i);
    }
    ft_list_remove_if(&lst, data_ref, cmp, free_fct);
    check("removed:", list_check_if(lst, data_ref, cmp) == 0);
    check("free_fct call:", g_ff_access == expected_ff);
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

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    list_remove_if_tester();
}
