#include "libunit.h"
#include "_read.h"

int	read_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "one char, return value", &read_01, FLAG_STDIN);
	test_loader(&test, "one char, data read", &read_02, FLAG_STDIN);
	test_loader(&test, "short, return value", &read_03, FLAG_STDIN);
	test_loader(&test, "short, data read", &read_04, FLAG_STDIN);
	test_loader(&test, "long, return value", &read_05, FLAG_STDIN);
	test_loader(&test, "long, data read", &read_06, FLAG_STDIN);
	test_loader(&test, "error: EBADFD , return value", &read_07, FLAG_STDIN);
	test_loader(&test, "error: EBADFD , errno value", &read_08, FLAG_STDIN);
	test_loader(&test, "error: NULL buf, return value", &read_09, FLAG_STDIN);
	test_loader(&test, "error: NULL buf, errno value", &read_10, FLAG_STDIN);
	return (test_launcher(&test, "READ"));
}
