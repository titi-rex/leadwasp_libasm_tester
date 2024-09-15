#include "_read.h"

int	read_02(void)
{
	const char		*str = REF_STRING;
	const size_t	len = 1;
	char			exp[len + 1];
	char			got[len + 1];

	write(STDOUT_FILENO, str, len);
	ssize_t	r_exp = read(STDIN_FILENO, exp, len);
	exp[r_exp] = '\0';

	write(STDOUT_FILENO, str, len);
	ssize_t	r_got = ft_read(STDIN_FILENO, got, len);
	got[r_got] = '\0';


	if (strncmp(exp, got, len + 1) == 0)
		return (0);
	else
		return (-1);
}
