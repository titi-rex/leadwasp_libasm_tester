#include "libunit.h"
#include "_list_remove_if.h"

int	list_remove_if_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "nothing, data removed", &list_remove_if_01, 0);
	test_loader(&test, "nothing, use of free_fct", &list_remove_if_02, 0);
	test_loader(&test, "one node, data removed", &list_remove_if_03, 0);
	test_loader(&test, "one node, use of free_fct", &list_remove_if_04, 0);
	test_loader(&test, "all node, data removed", &list_remove_if_05, 0);
	test_loader(&test, "all node, use of free_fct", &list_remove_if_06, 0);
	test_loader(&test, "half node, data removed", &list_remove_if_07, 0);
	test_loader(&test, "half node, use of free_fct", &list_remove_if_08, 0);
	test_loader(&test, "quarter node, data removed", &list_remove_if_09, 0);
	test_loader(&test, "quarter node, use of free_fct", &list_remove_if_10, 0);
	return (test_launcher(&test, "LIST_REMOVE_IF"));
}
