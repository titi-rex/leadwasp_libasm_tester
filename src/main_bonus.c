#include "libunit.h"
#include "tests.h"

int	main(int ac, char **argv)
{
	t_mifunc	ftab[N_LAUNCHER_BONUS];

	ftab[0].name = "atoi_base";
	ftab[0].f_ptr = &atoi_base_00_launcher;

	test_start(ftab, N_LAUNCHER_BONUS, ac, argv);
	return (0);
}
