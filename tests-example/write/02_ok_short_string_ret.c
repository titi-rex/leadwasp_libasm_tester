#include "libunit.h"
#include "tests.h"

int	ok_short_string_ret(void)
{
	char	*ref;
	size_t	len;
	size_t	n;

	ref = "hello world!";
	len = strlen(ref);

	n = write(STDOUT_FILENO, ref, len);
	if (n == len)
			return (0);
	return (-1);
}
