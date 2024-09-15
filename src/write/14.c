#include "_write.h"

int	write_14(void)
{
	const char	*str = NULL;
	size_t		len = 1;
	int			exp;
	int			got;

	errno = 0;
	exp = write(BADFDS, str, len);
	if (exp != -1)
		return (-2);
	exp = errno;

	errno = 0;
	ft_write(BADFDS, str, len);
	got = errno;

	if (exp == got)
		return (0);
	else
		return (-1);
}
