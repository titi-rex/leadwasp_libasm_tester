#include "libunit.h"
#include "tests.h"

int	strlen_01(void)
{
	const char	*str = "";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
