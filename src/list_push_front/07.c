#include "_list_push_front.h"

int	list_push_front_07(void)
{
	char	*data = "hello beautiful garden";
	char	*data2 = "what a nice night!!!";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data2);
	ft_list_push_front(&list, (void*)data);
	int res = (list->next->next == NULL);
	_listclear(&list);

	if (res == 1)
		return (0);
	else
		return (-1);
}
