#include "_list_push_front.h"

int	list_push_front_10(void)
{
	char	*data1 = "hello beautiful garden";
	char	*data2 = "what a nice night!!!";
	char	*data3 = "whawtwtght!!!";
	char	*data4 = "wt3w3tnight!!!";
	char	*data5 = "wuyjmyuknice night!!!";
	char	*data6 = "yukyukuyight!!!";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data6);
	ft_list_push_front(&list, (void*)data5);
	ft_list_push_front(&list, (void*)data4);
	ft_list_push_front(&list, (void*)data3);
	ft_list_push_front(&list, (void*)data2);
	ft_list_push_front(&list, (void*)data1);
	void* res = list->next->next->next->next->next->next;
	_listclear(&list);

	if (res == NULL)
		return (0);
	else
		return (-1);
}