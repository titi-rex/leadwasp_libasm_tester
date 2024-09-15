#ifndef TESTS_H
# define TESTS_H
// # include <unistd.h>
# include <stdlib.h>
// # include <string.h>
// # include <stdio.h>
// # include <stdint.h>
// # include <stdbool.h>
// # include <signal.h>
// # include <assert.h>
// # include <errno.h>
// # include <fcntl.h>
// # include <malloc.h>
// # include <time.h>

# include "libasm.h"

# define N_LAUNCHER 6
# define N_LAUNCHER_BONUS 5

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
int	list_remove_if_00_launcher(void);
int	list_sort_00_launcher(void);
int	list_size_00_launcher(void);

#endif
