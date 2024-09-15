#include "_write.h"

int	write_13(void)
{
	const char	*str = NULL;
	size_t		len = 1;
	ssize_t		r_exp = write(STDOUT_FILENO, str, len);
	ssize_t		r_got = ft_write(STDOUT_FILENO, str, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}