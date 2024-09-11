#include "libunit.h"
#include "tests.h"

int	ok_short_string(void)
{
	char	*ref;
	char	buffer[50];
	size_t	len;
	int		n;

	ref = "hello world!";
	len = strlen(ref);

	write(STDOUT_FILENO, ref, len);
	n = read(STDIN_FILENO, buffer, len);
	
	if (n != -1)
	{
		buffer[n] = '\0';
		if (strncmp(buffer, ref, len) == 0)
			return (0);
	}
	return (-1);
}

