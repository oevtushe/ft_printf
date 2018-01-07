#include <stdlib.h>
#include "ft_tools.h"

void	ft_lstaddelem(t_list **lst, void **content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(*content, content_size);
	ft_lstappend(lst, new_elem);
	free(*content);
}
