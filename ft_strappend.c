#include "ft_printf.h"

void	ft_strappend(char **str, char c)
{
	size_t	len;
	char	*res;

	res = NULL;
	len = (*str) ? ft_strlen(*str) : 0;
	res = ft_strnew(len + 1);
	if (*str)
		ft_strcpy(res, *str);
	res[len] = c;
	if (*str)
		free(*str);
	*str = res;
}
