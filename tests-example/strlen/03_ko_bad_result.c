#include "tests.h"

int	ko_bad_result(void)
{
	if (strlen("hello.") == 75)
		return (0);
	else
		return (-1);
}
