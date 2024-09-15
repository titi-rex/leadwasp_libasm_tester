#include "_list_sort.h"

int	list_sort_01(void)
{
	t_list	*list = NULL;

	ft_list_sort(&list, _cmp_int);
	int res = _list_sorted(list, _cmp_int);

	if (res == 0)
		return (0);
	else
		return (-1);
}
