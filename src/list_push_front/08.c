#include "_list_push_front.h"

int	list_push_front_08(void)
{
	char	*data1 = "hello beautiful garden";
	char	*data2 = "what a nice night!!!";
	char	*data3 = "57adawdawfawfht!!!";
	char	*data4 = "whawdawfawft!!!";
	char	*data5 = "what a nafafwa wdfawt!!!";
	char	*data6 = "awfafa\nw]afpwlat!!!";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data6);
	ft_list_push_front(&list, (void*)data5);
	ft_list_push_front(&list, (void*)data4);
	ft_list_push_front(&list, (void*)data3);
	ft_list_push_front(&list, (void*)data2);
	ft_list_push_front(&list, (void*)data1);
	int res = strcmp(data2, list->next->data);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}