#include "libunit.h"
#include "tests.h"

int	list_remove_if_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &list_remove_if_01, 0);
	test_loader(&test, "", &list_remove_if_02, 0);
	test_loader(&test, "", &list_remove_if_03, 0);
	test_loader(&test, "", &list_remove_if_04, 0);
	test_loader(&test, "", &list_remove_if_05, 0);
	test_loader(&test, "", &list_remove_if_06, 0);
	return (test_launcher(&test, ""));
}
