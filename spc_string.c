#include "ft_printf.h"

char		*spc_string(char **str, size_t new_len, char filler, char side)
{
	size_t	tjlen;
	char	*res;
	char	*to_join;

	tjlen = new_len - ft_strlen(*str);
	to_join = ft_strnew(tjlen);
	ft_memset(to_join, filler, tjlen);
	if (side == '-')
		res = ft_strjoin(*str, to_join);
	else
		res = ft_strjoin(to_join, *str);
	ft_strdel(*str);
	return (res);
}

