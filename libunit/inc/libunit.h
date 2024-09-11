/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:55:43 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/11 15:03:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

# define NAME_MAX_LENGHT 32
# define TIMEOUT 2
# define TIMEOUT_L 10
# define LOG_BUFFER_SIZE 300

# define INTERNAL_ERROR 1

# define FLAG_STDIN		0b00000001
# define FLAG_TIMEOUT_L	0b00000010

typedef int		(*t_test_func)(void);
typedef void	(*t_verbose)(void);

typedef struct s_meta_int_function
{
	char	*name;
	int		(*f_ptr)();
}	t_mifunc;



typedef struct s_test
{
	char			name[NAME_MAX_LENGHT];
	size_t			id;
	uint8_t			flags;
	uint8_t			status;
	t_test_func		function;
	t_verbose		scenario;
	struct s_test	*next;
}					t_test;

void	test_loader(t_test **test_list, char *test_name, t_test_func function, uint8_t flags);
int		test_launcher(t_test **test_list, const char *name);
int		test_start(t_mifunc *ftab, size_t len, int ac, char **argv);

#endif
