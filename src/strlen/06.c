#include "libunit.h"
#include "tests.h"

int	strlen_06(void)
{
	const char	*str = "hello my dear friend, what a nice day!.";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
