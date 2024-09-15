#ifndef __LIST_SORT_H_
# define __LIST_SORT_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <time.h>

# include "libasm.h"

void	_listclear(t_list **list);
void	_list_push_front(t_list **begin_list, void *data);

int		_cmp_int(void* a, void* b);
int		_cmp_str(void* a, void* b);
int		_list_sorted(t_list* head, int (*cmp)());


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

#endif
