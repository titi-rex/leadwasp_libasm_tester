#include "tests.h"

int	ko_segv(void)
{
	char	*str;

	str = NULL;
	return (strlen(str));
}
