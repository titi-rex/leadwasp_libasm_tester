#include "libunit.h"
#include "tests.h"

int	strdup_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty, malloc size", &strdup_01, 0);
	test_loader(&test, "empty, copy", &strdup_02, 0);
	test_loader(&test, "short, malloc size", &strdup_03, 0);
	test_loader(&test, "short, copy", &strdup_04, 0);
	test_loader(&test, "long, malloc size", &strdup_05, 0);
	test_loader(&test, "long, copy", &strdup_06, 0);
	test_loader(&test, "very long, malloc size", &strdup_07, 0);
	test_loader(&test, "very long, copy", &strdup_08, 0);
	test_loader(&test, "some non printable, malloc size", &strdup_09, 0);
	test_loader(&test, "some non printable, copy", &strdup_10, 0);
	return (test_launcher(&test, "STRDUP"));
}
