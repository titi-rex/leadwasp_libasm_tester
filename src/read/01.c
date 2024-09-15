#include "_read.h"

int	read_01(void)
{
	const char		*str = REF_STRING;
	const size_t	len = 1;
	char			exp[len + 1];
	char			got[len + 1];

	write(STDOUT_FILENO, str, len);
	ssize_t	r_exp = read(STDIN_FILENO, exp, len);

	write(STDOUT_FILENO, str, len);
	ssize_t	r_got = ft_read(STDIN_FILENO, got, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}
