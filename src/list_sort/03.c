#include "_list_sort.h"

int	list_sort_03(void)
{
	t_list	*list = NULL;

	srand(time(NULL));
	for(uint64_t i = 0; i < 15; i++)
	{
		uint64_t r = rand();
		_list_push_front(&list, (void*)r);
	}
	ft_list_sort(&list, _cmp_int);
	int res = _list_sorted(list, _cmp_int);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
