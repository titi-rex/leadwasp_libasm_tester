#include "libunit.h"
#include "tests.h"

int	list_size_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &list_size_01, 0);
	test_loader(&test, "", &list_size_02, 0);
	test_loader(&test, "", &list_size_03, 0);
	test_loader(&test, "", &list_size_04, 0);
	test_loader(&test, "", &list_size_05, 0);
	test_loader(&test, "", &list_size_06, 0);
	return (test_launcher(&test, ""));
}
