#include "libunit.h"
#include "tests.h"

int	main(int ac, char **argv)
{
	t_mifunc	ftab[N_LAUNCHER];

	ftab[0].name = "strlen";
	ftab[0].f_ptr = &strlen_00_launcher;
	ftab[1].name = "strcpy";
	ftab[1].f_ptr = &strcpy_00_launcher;
	ftab[2].name = "strcmp";
	ftab[2].f_ptr = &strcmp_00_launcher;
	ftab[3].name = "strdup";
	ftab[3].f_ptr = &strdup_00_launcher;
	ftab[4].name = "write";
	ftab[4].f_ptr = &write_00_launcher;
	ftab[5].name = "read";
	ftab[5].f_ptr = &read_00_launcher;

	test_start(ftab, N_LAUNCHER, ac, argv);
	return (0);
}
