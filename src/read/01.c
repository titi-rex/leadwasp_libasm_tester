#include "libunit.h"
#include "tests.h"

int	read_01(void)
{
	const char	*str = "";
	if (ft_(str) == (str))
		return (0);
	else
		return (-1);
}
