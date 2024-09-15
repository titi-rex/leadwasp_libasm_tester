#include "libunit.h"
#include "_list_sort.h"

int	list_sort_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, sorted", &list_sort_01, 0);
	test_loader(&test, "int, one element", &list_sort_02, 0);
	test_loader(&test, "int, short", &list_sort_03, 0);
	test_loader(&test, "int, long 1", &list_sort_04, 0);
	test_loader(&test, "int, long", &list_sort_05, 0);
	test_loader(&test, "string, short", &list_sort_06, 0);
	test_loader(&test, "string, long", &list_sort_07, 0);
	return (test_launcher(&test, "LIST_SORT"));
}
