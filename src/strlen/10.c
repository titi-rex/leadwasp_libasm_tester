#include "_strlen.h"

int	strlen_10(void)
{
	char	*str = "at last..";
	size_t	got = ft_strlen(str);
	size_t	exp = strlen(str);

	if (got == exp)
		return (0);
	else
		return (-1);
}