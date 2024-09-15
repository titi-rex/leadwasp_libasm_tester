#include "_list_size.h"

int	list_size_01(void)
{
	t_list	*list = NULL;

	int res = ft_list_size(list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
