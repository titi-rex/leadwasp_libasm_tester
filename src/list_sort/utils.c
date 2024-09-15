#include "_list_sort.h"

int _cmp_int(void* a, void* b)
{
    return ((uint64_t)a > (uint64_t)b);
}

int _cmp_str(void* a, void* b)
{
    return (strcmp(a, b) > 0);
}

int _list_sorted(t_list* head, int (*cmp)())
{
    while(head && head->next)
    {
        if ((*cmp)(head->data, head->next->data))
            return (1);
        head = head->next;
    }
    return (0);
}
