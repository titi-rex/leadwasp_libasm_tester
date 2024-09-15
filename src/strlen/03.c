#include "_strlen.h"

int	strlen_03(void)
{
	const char	*str = "a";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
