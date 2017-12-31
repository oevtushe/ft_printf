#include "ft_printf.h"

t_list			*init_assocs(void)
{
	t_list	*lst;
	t_list	*new_elem;
	t_assoc *assoc;

	lst = NULL;
	assoc = (t_assoc*)malloc(sizeof(t_assoc));
	assoc->type = 's';
	assoc->manager = string_manager;
	new_elem = ft_lstnew(assoc, sizeof(t_assoc));
	ft_lstappend(&lst, new_elem);
	free(assoc);
	return (lst);
}
