#include "_list_remove_if.h"

int g_ff_access = 0;

int    _list_check_if(t_list *head, void *data_ref, int (*cmp)())
{
    while(head)
    {
        if ((*cmp)(head->data, data_ref) == 0)
            return (1);
        head = head->next;
    }
    return (0);
}

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

