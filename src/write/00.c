#include "libunit.h"
#include "_write.h"

int	write_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, return value", &write_01, FLAG_STDIN);
	test_loader(&test, "empty, data written", &write_02, FLAG_STDIN);
	test_loader(&test, "one char, return value", &write_03, FLAG_STDIN);
	test_loader(&test, "one char, data written", &write_04, FLAG_STDIN);
	test_loader(&test, "short, return value", &write_05, FLAG_STDIN);
	test_loader(&test, "short, data written", &write_06, FLAG_STDIN);
	test_loader(&test, "long, return value", &write_07, FLAG_STDIN);
	test_loader(&test, "long, data written", &write_08, FLAG_STDIN);
	test_loader(&test, "non printable, return value", &write_09, FLAG_STDIN);
	test_loader(&test, "non printable, data written", &write_10, FLAG_STDIN);
	test_loader(&test, "error: EBADF, return value", &write_11, FLAG_STDIN);
	test_loader(&test, "error: EBADF, errno value", &write_12, FLAG_STDIN);
	test_loader(&test, "error: str NULL, return value", &write_13, FLAG_STDIN);
	test_loader(&test, "error: str NULL, errno value", &write_14, FLAG_STDIN);
	test_loader(&test, "error: EPIPE, return value", &write_15, FLAG_STDIN);
	test_loader(&test, "error: EPIPE, errno value", &write_16, FLAG_STDIN);
	return (test_launcher(&test, "WRITE"));
}


// test retur nvalue 
// test errno
// test data written