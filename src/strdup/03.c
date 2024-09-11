#include "libunit.h"
#include "tests.h"

int	strdup_03(void)
{
	const char	*src = "hehe";
	char	*exp = ft_strdup(src);
	char	*got = strdup(src);

	size_t	s_exp = malloc_usable_size(exp);
	size_t	s_got = malloc_usable_size(got);

	free(exp);
	free(got);
	if (s_exp == s_got)
		return (0);
	else
		return (-1);
}
