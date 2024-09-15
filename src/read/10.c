#include "_read.h"

int	read_10(void)
{
	const char		*str = REF_STRING;
	char			*buff = NULL;
	const size_t	len = 40;
	int				exp;
	int				got;

	write(STDOUT_FILENO, str, len);
	errno = 0;
	exp = read(STDIN_FILENO, buff, len);
	if (exp != -1)
		return (-2);
	exp = errno;

	write(STDOUT_FILENO, str, len);
	errno = 0;
	ft_read(STDIN_FILENO, buff, len);
	got = errno;

	if (exp == got)
		return (0);
	else
		return (-1);
}