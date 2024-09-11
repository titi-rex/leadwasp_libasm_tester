#include "libunit.h"
#include "tests.h"

int	read_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &read_01, 0);
	test_loader(&test, "", &read_02, 0);
	test_loader(&test, "", &read_03, 0);
	test_loader(&test, "", &read_04, 0);
	test_loader(&test, "", &read_05, 0);
	test_loader(&test, "", &read_06, 0);
	return (test_launcher(&test, ""));
}
