#include "libunit.h"
#include "tests.h"

int	strcmp_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, empty", &strcmp_01, 0);
	test_loader(&test, "one char, empty", &strcmp_02, 0);
	test_loader(&test, "empty, one char", &strcmp_03, 0);
	test_loader(&test, "short string, empty", &strcmp_04, 0);
	test_loader(&test, "empty, short string", &strcmp_05, 0);
	test_loader(&test, "long, long" , &strcmp_06, 0);
	test_loader(&test, "long, long (same len)", &strcmp_07, 0);
	test_loader(&test, "same src", &strcmp_08, 0);
	test_loader(&test, "equal, short", &strcmp_09, 0);
	test_loader(&test, "equal, long", &strcmp_10, 0);
	return (test_launcher(&test, "STRCMP"));
}
