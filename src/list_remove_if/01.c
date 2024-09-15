#include "_list_remove_if.h"

int	list_remove_if_01(void)
{
	t_list	*list = NULL;

	for(uint64_t i = 0; i < 21; i++)
	{
		_list_push_front(&list, (void*)i);
	}
	ft_list_remove_if(&list, (void*)51, _cmp_equ, _fake_free);
	int res = _list_check_if(list, (void*)51, _cmp_equ);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
