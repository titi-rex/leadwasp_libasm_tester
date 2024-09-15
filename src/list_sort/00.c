#include "libunit.h"
#include "_list_sort.h"

int	list_sort_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &list_sort_01, 0);
	test_loader(&test, "", &list_sort_02, 0);
	test_loader(&test, "", &list_sort_03, 0);
	test_loader(&test, "", &list_sort_04, 0);
	test_loader(&test, "", &list_sort_05, 0);
	test_loader(&test, "", &list_sort_06, 0);
	return (test_launcher(&test, ""));
}
