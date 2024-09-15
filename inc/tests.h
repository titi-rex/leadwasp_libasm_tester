#ifndef TESTS_H
# define TESTS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <signal.h>
# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <malloc.h>
# include <time.h>

# include "libasm.h"

# define N_LAUNCHER 6
# define N_LAUNCHER_BONUS 1

// mandatory
int	strlen_00_launcher(void);
int	strcpy_00_launcher(void);
int	strcmp_00_launcher(void);
int	strdup_00_launcher(void);
int	write_00_launcher(void);
int	read_00_launcher(void);


// bonus
int	atoi_base_00_launcher(void);
int	list_push_front_00_launcher(void);


int	list_push_front_01(void);
int	list_push_front_02(void);
int	list_push_front_03(void);
int	list_push_front_04(void);
int	list_push_front_05(void);
int	list_push_front_06(void);
int	list_push_front_07(void);
int	list_push_front_08(void);
int	list_push_front_09(void);
int	list_push_front_10(void);

int	list_remove_if_00_launcher(void);
int	list_remove_if_01(void);
int	list_remove_if_02(void);
int	list_remove_if_03(void);
int	list_remove_if_04(void);
int	list_remove_if_05(void);
int	list_remove_if_06(void);
int	list_remove_if_07(void);
int	list_remove_if_08(void);
int	list_remove_if_09(void);
int	list_remove_if_10(void);

int	list_sort_00_launcher(void);
int	list_sort_01(void);
int	list_sort_02(void);
int	list_sort_03(void);
int	list_sort_04(void);
int	list_sort_05(void);
int	list_sort_06(void);
int	list_sort_07(void);
int	list_sort_08(void);
int	list_sort_09(void);
int	list_sort_10(void);

int	list_size_00_launcher(void);
int	list_size_01(void);
int	list_size_02(void);
int	list_size_03(void);
int	list_size_04(void);
int	list_size_05(void);
int	list_size_06(void);
int	list_size_07(void);
int	list_size_08(void);
int	list_size_09(void);
int	list_size_10(void);

#endif
