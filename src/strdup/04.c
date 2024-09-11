#include "libunit.h"
#include "tests.h"

int	strdup_04(void)
{
	const char	*src = "hehe";
	char	*exp = ft_strdup(src);
	char	*got = strdup(src);

	int	res = strcmp(exp, got);

	free(exp);
	free(got);
	if (res == 0)
		return (0);
	else
		return (-1);
}
