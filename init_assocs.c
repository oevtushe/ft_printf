#include "ft_printf.h"

static   t_assoc			*new_assoc(char type, char *(*mgr)(t_format*, const void*))
{
	t_assoc *assoc;

	assoc = (t_assoc*)malloc(sizeof(t_assoc));
	assoc->type = type;
	assoc->manager = mgr;
	return (assoc);
}

t_list			*init_assocs(void)
{
	t_list	*lst;
	t_list	*new_elem;
	t_assoc *assoc;

	lst = NULL;
	assoc = new_assoc('s', string_manager);
	new_elem = ft_lstnew(assoc, sizeof(t_assoc));
	ft_lstappend(&lst, new_elem);
	free(assoc);
	assoc = new_assoc('d', string_manager);
	new_elem = ft_lstnew(assoc, sizeof(t_assoc));
	ft_lstappend(&lst, new_elem);
	free(assoc);
	return (lst);
}
