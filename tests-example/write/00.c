#include "libunit.h"
#include "tests.h"

int	write_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "OK short", &ok_short_string, FLAG_STDIN);
	test_loader(&test, "OK short return", &ok_short_string_ret, FLAG_STDIN);
	test_loader(&test, "OK empty", &ok_empty, FLAG_STDIN);
	test_loader(&test, "KO bad fd", &ko_bad_fd, FLAG_STDIN);
	return (test_launcher(&test, "WRITE"));
}

