#include "libunit.h"
#include "tests.h"

int	ko_bad_fd(void)
{
	if (write(123, "hello world!", 13) == 13)
		return (0);
	else
		return (-1);
}
