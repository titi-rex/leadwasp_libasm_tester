#include "_write.h"

int	write_11(void)
{
	const char	*str = "hello";
	size_t		len = strlen(str);
	ssize_t		r_exp = write(BADFDS, str, len);
	ssize_t		r_got = ft_write(BADFDS, str, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}
