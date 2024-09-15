#include "libunit.h"
#include "tests.h"

int	main(int ac, char **argv)
{
	t_mifunc	ftab[N_LAUNCHER_BONUS];

	ftab[0].name = "atoi_base";
	ftab[0].f_ptr = &atoi_base_00_launcher;
	ftab[1].name = "list_push_front";
	ftab[1].f_ptr = &list_push_front_00_launcher;
	ftab[2].name = "list_remove_if";
	ftab[2].f_ptr = &list_remove_if_00_launcher;
	ftab[3].name = "list_sort";
	ftab[3].f_ptr = &list_sort_00_launcher;
	ftab[4].name = "list_size";
	ftab[4].f_ptr = &list_size_00_launcher;

	test_start(ftab, N_LAUNCHER_BONUS, ac, argv);
	return (0);
}
