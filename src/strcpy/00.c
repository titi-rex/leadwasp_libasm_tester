#include "libunit.h"
#include "_strcpy.h"

int	strcpy_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, return value", &strcpy_01, 0);
	test_loader(&test, "empty, copy", &strcpy_02, 0);
	test_loader(&test, "len: 12, return value", &strcpy_03, 0);
	test_loader(&test, "len: 12, copy", &strcpy_04, 0);
	test_loader(&test, "len: 37, return value", &strcpy_05, 0);
	test_loader(&test, "len: 37, copy", &strcpy_06, 0);
	test_loader(&test, "len: 265, return value", &strcpy_07, 0);
	test_loader(&test, "len: 265, copy", &strcpy_08, 0);
	test_loader(&test, "len: 1017, return value", &strcpy_09, 0);
	test_loader(&test, "len: 1017, copy", &strcpy_10, 0);
	return (test_launcher(&test, "STRCPY"));
}
