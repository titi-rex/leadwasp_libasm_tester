#include "_list_push_front.h"

int	list_push_front_03(void)
{
	char	*data = "hello beautiful garden";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data);
	int res = (list->next == NULL);
	_listclear(&list);

	if (res == 1)
		return (0);
	else
		return (-1);
}
