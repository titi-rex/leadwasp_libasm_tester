#include "test.h"

int _cmp_int(void* a, void* b)
{
    return ((uint64_t)a > (uint64_t)b);
}

int _cmp_str(void* a, void* b)
{
    return (strcmp(a, b) > 0);
}

/*
Create the function ft_list_sort which sorts the list’s elements by ascending order
by comparing two elements by comparing their data with a function
Function pointed by cmp will be used as follows :    (*cmp)(list_ptr->data, list_other_ptr->data);
cmp could be for instance ft_strcmp.
*/
void    list_sort(t_list **begin_list, int (*cmp)())
{
    if (!begin_list || !*begin_list || !cmp)
        return ;

    t_list* current = *begin_list;
    while (current->next)
    {
        if ((*cmp)(current->data, current->next->data))
        {
            void*   tmp = current->data;
            t_list* next = current->next;
            current->data = next->data;
            next->data = tmp;
            list_sort(begin_list, cmp);
        }
        current = current->next;
    }
}

/**
 * @brief check if list is sorted using cmp
 * 
 * @param head 
 * @param cmp function to use for test
 * @return int 
 */
int list_sorted(t_list* head, int (*cmp)())
{
    while(head && head->next)
    {
        if ((*cmp)(head->data, head->next->data))
            return (1);
        head = head->next;
    }
    return (0);
}


void    list_sort_tester(void)
{
    t_list      *lst;
    uint64_t    len;

    printf("list_sort:\t");
    (void)len;

    // test empty list
    lst = NULL;
    ft_list_sort(&lst, _cmp_int);
    check(list_sorted(lst, _cmp_int) == 0);

    // test odd list
    lst = NULL;
    len = 37;
    for(uint64_t i = 0; i < len; i++)
    {
        uint64_t r =  i;
        list_push_front(&lst, (void*)r);
    }
    ft_list_sort(&lst, _cmp_int);
    check(list_sorted(lst, _cmp_int) == 0);
    listclear(&lst);

    // test even list
    lst = NULL;
    len = 52;
    for(uint64_t i = 0; i < len; i++)
    {
        uint64_t r =  i;
        list_push_front(&lst, (void*)r);
    }
    ft_list_sort(&lst, _cmp_int);
    check(list_sorted(lst, _cmp_int) == 0);
    listclear(&lst);


    // test string data list
    lst = NULL;
    char*   s1 = "ssello";
    char*   s2 = "aaaa";
    char*   s3 = "hello";
    char*   s4 = strdup("hello");
    list_push_front(&lst, s3);
    list_push_front(&lst, s2);
    list_push_front(&lst, s4);
    list_push_front(&lst, s1);
    ft_list_sort(&lst, _cmp_str);
    check(list_sorted(lst, _cmp_str) == 0);
    listclear(&lst);
    free(s4);


    printf("\n");
}

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    list_sort_tester();
}
