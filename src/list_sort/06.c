#include "_list_sort.h"

int	list_sort_06(void)
{
	t_list	*list = NULL;

	char*	s1 = "ssello";
	char*	s2 = "aaaa";
	char*	s3 = "hello";
	char*	s4 = "helilo";
	_list_push_front(&list, s3);
	_list_push_front(&list, s2);
	_list_push_front(&list, s4);
	_list_push_front(&list, s1);
	ft_list_sort(&list, _cmp_str);
	int res = _list_sorted(list, _cmp_str);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
