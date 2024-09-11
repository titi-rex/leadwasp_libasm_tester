#include "libunit.h"
#include "tests.h"

int	strdup_06(void)
{
	const char	*src = "hehslkfj sljfojes;ofh sf6s84efs4efsf jse9w73 os;l9es9rf9fru3u8sl38ursl83rus9w3l8ry sl3yr7sylwsi3rysiyr 3i7yslry3iyurslie";
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
