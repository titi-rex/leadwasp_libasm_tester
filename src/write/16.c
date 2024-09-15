#include "_write.h"

int	write_16(void)
{
	const char	*str = "hello";
	size_t		len = strlen(str);
	int			exp;
	int			got;
	int			fds[2];

	signal(SIGPIPE, SIG_IGN);

	if (pipe(fds) == -1)
		return (-2);

	close(fds[0]);

	errno = 0;
	exp = write(fds[1], str, len);
	if (exp != -1)
		return (-2);
	exp = errno;

	errno = 0;
	ft_write(fds[1], str, len);
	got = errno;

	if (exp == got)
		return (0);
	else
		return (-1);
}
