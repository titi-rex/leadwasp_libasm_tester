#include "_read.h"

int	read_09(void)
{
	const char		*str = REF_STRING;
	char			*buff = NULL;
	const size_t	len = 40;

	write(STDOUT_FILENO, str, len);
	ssize_t	r_exp = read(STDIN_FILENO, buff, len);

	write(STDOUT_FILENO, str, len);
	ssize_t	r_got = ft_read(STDIN_FILENO, buff, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}