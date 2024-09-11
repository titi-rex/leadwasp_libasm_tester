#include "test.h"

int g_verbose   = 0;

void    list_size_wrapper(int len)
{
    static int  i = 0;
    printf("%d.", i++);

    t_list  *lst = NULL;

    for(int i = 0; i < len; i++)
    {
        uint64_t r = 17;
        list_push_front(&lst, (void*)r);
    }
    int res = ft_list_size(lst);
    check("", res == len);
    listclear(&lst);
}

void    list_size_tester(void)
{
    printf("list_size:\t");
    list_size_wrapper(0);
    list_size_wrapper(1);
    list_size_wrapper(51);
    list_size_wrapper(524);
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    list_size_tester();
}
