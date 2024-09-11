#include "tests.h"

int	ok_short(void)
{
	if (strlen("hello") == 5)
		return (0);
	else
		return (-1);
}
