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

# define N_LAUNCHER 5

int	strlen_00_launcher(void);
int	strlen_01(void);
int	strlen_02(void);
int	strlen_03(void);
int	strlen_04(void);
int	strlen_05(void);
int	strlen_06(void);
int	strlen_07(void);
int	strlen_08(void);
int	strlen_09(void);
int	strlen_10(void);

int	strcpy_00_launcher(void);
int	strcpy_01(void);
int	strcpy_02(void);
int	strcpy_03(void);
int	strcpy_04(void);
int	strcpy_05(void);
int	strcpy_06(void);
int	strcpy_07(void);
int	strcpy_08(void);
int	strcpy_09(void);
int	strcpy_10(void);

int	strcmp_00_launcher(void);
int	strcmp_01(void);
int	strcmp_02(void);
int	strcmp_03(void);
int	strcmp_04(void);
int	strcmp_05(void);
int	strcmp_06(void);
int	strcmp_07(void);
int	strcmp_08(void);
int	strcmp_09(void);
int	strcmp_10(void);

int	strdup_00_launcher(void);
int	strdup_01(void);
int	strdup_02(void);
int	strdup_03(void);
int	strdup_04(void);
int	strdup_05(void);
int	strdup_06(void);
int	strdup_07(void);
int	strdup_08(void);
int	strdup_09(void);
int	strdup_10(void);

int	write_00_launcher(void);
int	write_01(void);
int	write_02(void);
int	write_03(void);
int	write_04(void);
int	write_05(void);
int	write_06(void);
int	write_07(void);
int	write_08(void);
int	write_09(void);
int	write_10(void);

int	read_00_launcher(void);
int	read_01(void);
int	read_02(void);
int	read_03(void);
int	read_04(void);
int	read_05(void);
int	read_06(void);
int	read_07(void);
int	read_08(void);
int	read_09(void);
int	read_10(void);

int	atoi_base_00_launcher(void);
int	atoi_base_01(void);
int	atoi_base_02(void);
int	atoi_base_03(void);
int	atoi_base_04(void);
int	atoi_base_05(void);
int	atoi_base_06(void);
int	atoi_base_07(void);
int	atoi_base_08(void);
int	atoi_base_09(void);
int	atoi_base_10(void);

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
