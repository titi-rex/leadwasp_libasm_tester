
/*
Create the function ft_list_sort which sorts the list’s elements by ascending order
by comparing two elements by comparing their data with a function
Function pointed by cmp will be used as follows :    (*cmp)(list_ptr->data, list_other_ptr->data);
cmp could be for instance ft_strcmp.
*/
void    list_sort(t_list **begin_list, int (*cmp)())
{
    if (!begin_list || !*begin_list || !cmp)
        return ;

    t_list* current = *begin_list;
    while (current->next)
    {
        if ((*cmp)(current->data, current->next->data))
        {
            void*   tmp = current->data;
            t_list* next = current->next;
            current->data = next->data;
            next->data = tmp;
            list_sort(begin_list, cmp);
        }
        current = current->next;
    }
}

/*
Create the function ft_list_size which returns the number of elements in the
list.
*/
int	list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

/*
Create the function ft_list_remove_if which removes from the list,
 all elements
whose data compared to data_ref using cmp, makes cmp return 0.
• The data from an element to be erased should be freed using 
free_fc
Function pointed by cmp and by free_fct will be used as follows :
    (*cmp)(list_ptr->data, data_ref);
    (*free_fct)(list_ptr->data);
*/
void    list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list* current = NULL;
    t_list* parent  = *begin_list;

    while (parent)
    {
        if ((*cmp)(parent->data, data_ref) == 0)
        {
            *begin_list = parent->next;
            (*free_fct)(parent->data);
            free(parent);
            parent = *begin_list;
        }
        else
        {
            current = parent->next;
            break ;
        }
    }

    while (current)
    {
        if ((*cmp)(current->data, data_ref) == 0)
        {
            parent->next = current->next;
            (*free_fct)(current->data);
            free(current);
        }
        else
            parent = current;
        current = parent->next;
    }
}

