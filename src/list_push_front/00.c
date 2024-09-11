#include "libunit.h"
#include "tests.h"

int	list_push_front_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &list_push_front_01, 0);
	test_loader(&test, "", &list_push_front_02, 0);
	test_loader(&test, "", &list_push_front_03, 0);
	test_loader(&test, "", &list_push_front_04, 0);
	test_loader(&test, "", &list_push_front_05, 0);
	test_loader(&test, "", &list_push_front_06, 0);
	return (test_launcher(&test, ""));
}
