#ifndef __LIST_REMOVE_IF_H_
# define __LIST_REMOVE_IF_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include "libasm.h"

void	_listclear(t_list **list);
void	_list_push_front(t_list **begin_list, void *data);

int		_cmp_mod(void* a, void* b);
int		_cmp_equ(void* a, void* b);
void	_fake_free(void* a);
int		_list_check_if(t_list *head, void *data_ref, int (*cmp)());

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

#endif
