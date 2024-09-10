#include "tests.h"

int	ko_timeout(void)
{
	int	i;

	i = 0;
	while (1)
	{
		sleep(1);
		i++;
	}
	return (0);
}
