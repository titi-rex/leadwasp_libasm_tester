#include "_list_remove_if.h"

extern int g_ff_access;

int	list_remove_if_08(void)
{
	t_list	*list = NULL;

	g_ff_access = 0;
	for(uint64_t i = 0; i < 21; i++)
	{
		_list_push_front(&list, (void*)i);
	}
	ft_list_remove_if(&list, (void*)2, _cmp_mod, _fake_free);
	_listclear(&list);

	if (g_ff_access == 11)
		return (0);
	else
		return (-1);
}