#include "libunit.h"
#include "tests.h"

int	strdup_05(void)
{
	const char	*src = "hehslkfj sljfojes;ofh sf6s84efs4efsf jse9w73 os;l9es9rf9fru3u8sl38ursl83rus9w3l8ry sl3yr7sylwsi3rysiyr 3i7yslry3iyurslie";
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
