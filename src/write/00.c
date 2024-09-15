#include "libunit.h"
#include "_write.h"

int	write_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, return value", &write_01, 0);
	test_loader(&test, "empty, data written", &write_02, 0);
	// test_loader(&test, "one char, return value", &write_03, 0);
	// test_loader(&test, "one char, data written", &write_04, 0);
	test_loader(&test, "short, return value", &write_05, 0);
	test_loader(&test, "short, data written", &write_06, 0);
	// test_loader(&test, "long, return value", &write_07, 0);
	// test_loader(&test, "long, data written", &write_08, 0);
	// test_loader(&test, "non printable, return value", &write_09, 0);
	// test_loader(&test, "non printable, data written", &write_10, 0);
	// test_loader(&test, "error: , return value", &write_11, 0);
	// test_loader(&test, "error: , errno value", &write_12, 0);
	return (test_launcher(&test, "WRITE"));
}


// test retur nvalue 
// test errno
// test data written