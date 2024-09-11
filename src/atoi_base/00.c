#include "libunit.h"
#include "tests.h"

int	atoi_base_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &atoi_base_01, 0);
	test_loader(&test, "", &atoi_base_02, 0);
	test_loader(&test, "", &atoi_base_03, 0);
	test_loader(&test, "", &atoi_base_04, 0);
	test_loader(&test, "", &atoi_base_05, 0);
	test_loader(&test, "", &atoi_base_06, 0);
	return (test_launcher(&test, ""));
}
