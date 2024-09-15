#include "_strlen.h"

void	sighandler(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}

int	strlen_02(void)
{
	const char	*str = NULL;

	signal(SIGSEGV, sighandler);
	ft_strlen(str);
	return (-1);
}
