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

# define N_LAUNCHER 4



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

int	dummy_00_launcher(void);
int	dummy_01(void);
int	dummy_02(void);
int	dummy_03(void);
int	dummy_04(void);
int	dummy_05(void);
int	dummy_06(void);
int	dummy_07(void);
int	dummy_08(void);
int	dummy_09(void);
int	dummy_10(void);

#endif
