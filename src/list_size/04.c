#include "_list_size.h"

int	list_size_04(void)
{
	t_list	*list = NULL;

	for(int i = 0; i < 151; i++)
	{
		_list_push_front(&list, (void*)17);
	}
	int res = ft_list_size(list);
	_listclear(&list);

	if (res == 151)
		return (0);
	else
		return (-1);
}
