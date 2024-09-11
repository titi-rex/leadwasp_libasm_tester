#include "libunit.h"
#include "tests.h"

int	strcmp_01(void)
{
	const char	*s1 = "";
	const char	*s2 = "";
	int exp = strcmp(s1, s2);
	int got = ft_strcmp(s1, s2);

	if ((exp == got) || (exp < 0 && got < 0) || (exp > 0 && got > 0))
		return (0);
	else
		return (-1);
}
