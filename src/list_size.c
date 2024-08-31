#include "test.h"


/*
Create the function ft_list_size which returns the number of elements in the
list.
*/
int	list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}


void    list_size_wrapper(int len)
{
    t_list  *lst = NULL;

    for(int i = 0; i < len; i++)
    {
        uint64_t r = 17;
        list_push_front(&lst, (void*)r);
    }
    int res = ft_list_size(lst);
    check(res == len);
    // printf("exp: %d, got: %d\n", len, res);
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

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    list_size_tester();
}
