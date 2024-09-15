#include "libunit.h"
#include "_strlen.h"

int	strlen_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &strlen_01, 0);
	test_loader(&test, "crash on null", &strlen_02, 0);
	test_loader(&test, "len: 1", &strlen_03, 0);
	test_loader(&test, "len: 2", &strlen_04, 0);
	test_loader(&test, "len: 10", &strlen_05, 0);
	test_loader(&test, "len: 39", &strlen_06, 0);
	test_loader(&test, "len: 365", &strlen_07, 0);
	test_loader(&test, "len: 6524", &strlen_08, 0);
	test_loader(&test, "len 10124", &strlen_09, 0);
	test_loader(&test, "last", &strlen_10, 0);
	return (test_launcher(&test, "STRLEN"));
}
