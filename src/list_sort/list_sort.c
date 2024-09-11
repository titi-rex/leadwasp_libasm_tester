#include "test.h"

int g_verbose   = 0;

int _cmp_int(void* a, void* b)
{
    return ((uint64_t)a > (uint64_t)b);
}

int _cmp_str(void* a, void* b)
{
    return (strcmp(a, b) > 0);
}

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

void    _list_sort_tester_uint(uint64_t len)
{
    static int  i = 1;
    printf("%d.", i++);

    t_list      *lst = NULL;

    for(uint64_t i = 0; i < len; i++)
    {
        uint64_t r = rand();
        list_push_front(&lst, (void*)r);
    }
    ft_list_sort(&lst, _cmp_int);
    check("", list_sorted(lst, _cmp_int) == 0);
    if (lst)
        listclear(&lst);
}


void    list_sort_tester(void)
{
    printf("list_sort:\t");
    srand(time(NULL));

    // test string data list
    t_list* lst = NULL;
    char*   s1 = "ssello";
    char*   s2 = "aaaa";
    char*   s3 = "hello";
    char*   s4 = strdup("hello");
    list_push_front(&lst, s3);
    list_push_front(&lst, s2);
    list_push_front(&lst, s4);
    list_push_front(&lst, s1);
    ft_list_sort(&lst, _cmp_str);
    printf("0.");
    check("", list_sorted(lst, _cmp_str) == 0);
    listclear(&lst);
    free(s4);

    // test empty list
    _list_sort_tester_uint(0);
    // test odd list
    _list_sort_tester_uint(1);
    // test odd list
    _list_sort_tester_uint(37);
    // test odd list
    _list_sort_tester_uint(52);
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    list_sort_tester();
}
