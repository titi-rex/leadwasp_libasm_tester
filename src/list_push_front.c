#include "test.h"

int g_verbose   = 0;

void    list_push_front_wrapper(t_list** list, void* data, t_list* exp_next, long int exp_msize)
{
    static int  i = 0;
    printf("%d.", i++);

    ft_list_push_front(list, data);

    check("head:", *list != NULL);
    if (*list == NULL)
        return ;
    long int mus = malloc_usable_size(*list);
    check("msize:", mus == exp_msize);
    check("data:", (*list)->data == data);
    check("next:", (*list)->next == exp_next);
}

void    list_push_front_tester(void)
{
    printf("list_push_front: ");
    t_list* list = NULL;
    t_list  *tmp = malloc(sizeof(t_list));
    long int    exp_msize = malloc_usable_size(tmp);
    free(tmp);

    char*   str = "dd";
    list_push_front_wrapper(&list, (void*)str, NULL, exp_msize);
    t_list* save = list;

    int     i = 48;
    list_push_front_wrapper(&list, (void*)&i, list, exp_msize);

    int     tab[37];
    list_push_front_wrapper(&list, (void*)tab, list, exp_msize);

    printf("all.");
    if (list != NULL && list->next != NULL && list->next->next != NULL)
    {
        check("", list->next->next == save);
        check("", list->next->next->data == (void*)str);
        check("", list->next->next->next == NULL);
    }
    else
        check("", 1 == 2);
    listclear(&list);
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    list_push_front_tester();
}
