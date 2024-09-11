#include "libunit.h"
#include "tests.h"

int	main(int ac, char **argv)
{
	t_mifunc	ftab[N_LAUNCHER];

	ftab[0].name = "strlen";
	ftab[0].f_ptr = &strlen_launcher;
	ftab[1].name = "write";
	ftab[1].f_ptr = &write_launcher;

	test_start(ftab, N_LAUNCHER, ac, argv);
	return (0);
}
