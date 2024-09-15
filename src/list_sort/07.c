#include "_list_sort.h"

int	list_sort_07(void)
{
	t_list	*list = NULL;

	char*	s1 = "ssello";
	char*	s2 = "aaaa";
	char*	s3 = "sef";
	char*	s4 = "3rwsdfr";
	char*	s5 = "helilo";
	char*	s6 = "asd";
	char*	s7 = "gzsd";
	char*	s8 = "gzdgr";
	char*	s9 = "uiyil";
	char*	s10 = "i9ou";
	_list_push_front(&list, s3);
	_list_push_front(&list, s6);
	_list_push_front(&list, s2);
	_list_push_front(&list, s4);
	_list_push_front(&list, s5);
	_list_push_front(&list, s9);
	_list_push_front(&list, s8);
	_list_push_front(&list, s1);
	_list_push_front(&list, s10);
	_list_push_front(&list, s7);
	ft_list_sort(&list, _cmp_str);
	int res = _list_sorted(list, _cmp_str);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
