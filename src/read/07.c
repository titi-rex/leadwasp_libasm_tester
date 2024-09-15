#include "_read.h"

extern int errno;

int	read_07(void)
{
	char			buff[50];
	const size_t	len = 40;

	ssize_t	r_exp = read(BADFDS, buff, len);
	ssize_t	r_got = ft_read(BADFDS, buff, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}


