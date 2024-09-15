#ifndef __LIST_SIZE_H_
# define __LIST_SIZE_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include "libasm.h"

void	_listclear(t_list **list);
void	_list_push_front(t_list **begin_list, void *data);

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
