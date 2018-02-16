#include "ft_printf_helpers.h"

/*
** split_str fills plain and format lists.
** plain list will be filled with simple text.
** format list will be filled with format strings.
*/

void	split_str(const char *str, t_list **plain, t_list **format)
{
	size_t		prev;
	size_t		pos;
	char		*tmp;

	prev = 0;
	while ((tmp = ft_strchr(&(str[prev]), '%')))
	{
		pos = tmp - str;
		tmp = ft_strsub(str, prev, pos - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
		tmp = get_format_string(str, &pos);
		ft_lstaddelem(format, (void**)(&tmp), ft_strlen(tmp) + 1);
		prev = pos;
	}
	if (prev != ft_strlen(str))
	{
		tmp = ft_strsub(str, prev, ft_strlen(str) - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
	}
}
