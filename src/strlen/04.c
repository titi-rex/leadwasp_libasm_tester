#include "libunit.h"
#include "tests.h"

int	strlen_04(void)
{
	const char	*str = "a1";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
