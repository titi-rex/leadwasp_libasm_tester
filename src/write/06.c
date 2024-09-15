#include "_write.h"

int	write_06(void)
{
	const char	*str = "simple pipple riggle... !@#q32q3";
	size_t		len = strlen(str);

	char		*exp = calloc(len + 1, sizeof(char));
	char		*got = calloc(len + 1, sizeof(char));

	if (!exp || !got)
		return (-2);

	write(STDOUT_FILENO, str, len);
	read(STDIN_FILENO, exp, len);
	
	ft_write(STDOUT_FILENO, str, len);
	read(STDIN_FILENO, got, len);

	int	ret = strncmp(exp, got, len);

	free(exp);
	free(got);

	if (ret == 0)
		return (0);
	else
		return (-1);
}
