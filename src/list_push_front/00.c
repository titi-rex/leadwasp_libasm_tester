#include "libunit.h"
#include "_list_push_front.h"

int	list_push_front_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "first node, creation", &list_push_front_01, 0);
	test_loader(&test, "first node, data", &list_push_front_02, 0);
	test_loader(&test, "first node, next", &list_push_front_03, 0);
	test_loader(&test, "2nd node, creation", &list_push_front_04, 0);
	test_loader(&test, "2nd node, 1st data", &list_push_front_05, 0);
	test_loader(&test, "2nd node, 2nd data", &list_push_front_06, 0);
	test_loader(&test, "2nd node, next", &list_push_front_07, 0);
	test_loader(&test, "long list, data", &list_push_front_08, 0);
	test_loader(&test, "long list, data2", &list_push_front_09, 0);
	test_loader(&test, "long list, next", &list_push_front_10, 0);
	return (test_launcher(&test, "LIST_PUSH_FRONT"));
}
