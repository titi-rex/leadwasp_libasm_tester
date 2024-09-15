#include "_list_push_front.h"

int	list_push_front_05(void)
{
	char	*data = "hello beautiful garden";
	char	*data2 = "what a nice night!!!";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data2);
	ft_list_push_front(&list, (void*)data);
	int res = strcmp(data, list->data);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
