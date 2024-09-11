#include "libunit.h"
#include "tests.h"

int	ok_empty(void)
{
	if (write(1, "", 1) == 1)
		return (0);
	return (-1);
}
