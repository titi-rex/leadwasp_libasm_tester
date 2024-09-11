#include "libunit.h"
#include "tests.h"

int	strlen_05(void)
{
	const char	*str = "akelok7! p";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
