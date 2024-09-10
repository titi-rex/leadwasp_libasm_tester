#include "tests.h"

int	ko_buse(void)
{
	raise(SIGBUS);
	return (0);
}
