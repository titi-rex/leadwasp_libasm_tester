#include "_write.h"



int	write_15(void)
{
	const char	*str = "hello";
	size_t		len = strlen(str);
	int			fds[2];

	signal(SIGPIPE, SIG_IGN);

	if (pipe(fds) == -1)
		return (-2);

	close(fds[0]);

	ssize_t		r_exp = write(fds[1], str, len);
	ssize_t		r_got = ft_write(fds[1], str, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}