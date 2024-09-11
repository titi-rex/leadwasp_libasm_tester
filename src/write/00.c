#include "libunit.h"
#include "tests.h"

int	write_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty", &write_01, 0);
	test_loader(&test, "", &write_02, 0);
	test_loader(&test, "", &write_03, 0);
	test_loader(&test, "", &write_04, 0);
	test_loader(&test, "", &write_05, 0);
	test_loader(&test, "", &write_06, 0);
	test_loader(&test, "", &write_07, 0);
	test_loader(&test, "", &write_08, 0);
	test_loader(&test, "", &write_09, 0);
	test_loader(&test, "", &write_10, 0);
	return (test_launcher(&test, "WRITE"));
}


// test retur nvalue 
// test errno
// test data written