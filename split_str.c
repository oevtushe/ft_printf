#include "ft_printf.h"

void	free_format(t_format **format)
{
	free((*format)->flags);
	free(*format);
}

void	lst_addelem(t_list **lst, void *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(content, content_size);
	ft_lstappend(lst, new_elem);
	free(content);
}

void	split_str(const char *str, t_list **plain, t_list **format)
{
	size_t		prev;
	size_t		pos;
	char		*tmp;
	t_defaults	*defaults;

	prev = 0;
	defaults = init_defaults();
	while ((tmp = ft_strchr(&(str[prev]), '%')))
	{
		pos = tmp - str;
		tmp = ft_strsub(str, prev, pos - prev);
		lst_addelem(plain, tmp, ft_strlen(tmp) + 1);
		tmp = (void*)format_parser(str, defaults, &pos);
		lst_addelem(format, tmp, sizeof(t_format));
		prev = pos + 1;
	}
	if (prev != ft_strlen(str))
	{
		tmp = ft_strsub(str, prev, ft_strlen(str) - prev);
		lst_addelem(plain, tmp, ft_strlen((char*)tmp) + 1);
	}
}
