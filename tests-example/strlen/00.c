#include "libunit.h"
#include "tests.h"

int	strlen_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "OK short", &ok_short, 0);
	test_loader(&test, "OK long", &ok_long, 0);
	test_loader(&test, "KO bad result", &ko_bad_result, 0);
	test_loader(&test, "Null test", &ko_segv, 0);
	test_loader(&test, "Bus Error test", &ko_buse, 0);
	test_loader(&test, "Sleep test", &ko_timeout, 0);
	return (test_launcher(&test, "STRLEN"));
}

