#include "test.h"


void    list_push_front_wrapper(t_list** list, void* data, t_list* exp_next, long int exp_msize)
{
    ft_list_push_front(list, data);

    check(*list != NULL);
    if (*list == NULL)
    {
        printf("head NULL ");
        return ;
    }
    printf("ms.");
    long int mus = malloc_usable_size(*list);
    check(mus == exp_msize);
    // printf("mus: %ld, exp: %ld\n", mus, exp_msize);
    check((*list)->data == data);
    // printf("&data, got: %p, exp: %p\n", (*list)->data, data);
    check((*list)->next == exp_next);
    // printf("&next, got: %p, exp: %p\n", (*list)->next, exp_next);
}

void    list_push_front_tester(void)
{
    printf("list_push_front:\t");
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

    printf("spe:");
    if (list != NULL && list->next != NULL && list->next->next != NULL)
    {
        check(list->next->next == save);
        check(list->next->next->data == (void*)str);
        check(list->next->next->next == NULL);
    }
    else
        check(1 == 2);


    listclear(&list);
    printf("\n");
}
