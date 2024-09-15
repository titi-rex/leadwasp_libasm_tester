#include "libunit.h"
#include "_list_size.h"

int	list_size_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "empty list", &list_size_01, 0);
	test_loader(&test, "one element", &list_size_02, 0);
	test_loader(&test, "short", &list_size_03, 0);
	test_loader(&test, "middle", &list_size_04, 0);
	test_loader(&test, "long", &list_size_05, 0);
	return (test_launcher(&test, "LIST_SIZE"));
}
