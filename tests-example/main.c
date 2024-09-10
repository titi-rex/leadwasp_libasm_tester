#include "libunit.h"
#include "tests.h"

int	main(void)
{
	int	ret;

	ret = 0;
	ret += strlen_launcher();
	ret += write_launcher();
	if (ret < 0)
		ret = -1;
	return (0);
}
