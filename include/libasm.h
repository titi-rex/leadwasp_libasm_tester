#ifndef LIBASM_H
# define LIBASM_H
# include <sys/types.h>

size_t  ft_strlen(const char *s);
char *  ft_strcpy(char *restrict dst, const char *restrict src);
int     ft_strcmp(const char *s1, const char *s2);
char *  ft_strdup(const char *s);
ssize_t ft_write(int fd, const void* buf, size_t count);
ssize_t ft_read(int fd, void* buf, size_t count);

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

int     ft_atoi_base(char *str, char *base);

t_list *ft_create_elem(void *data);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*cmp)());
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));


#endif
