#include "ft_printf_helpers.h"

char	*str_add_prefix(char **str, int *len, char c)
{
	char	*tmp;
	char	*res;

	res = ft_strnew(1);
	res[0] = c;
	tmp = res;
	res = ft_strjoin(res, *str);
	++(*len);
	free(tmp);
	ft_strdel(str);
	return (res);
}

char	*easy_joiner(char *str, char *fst, char *scd)
{
	char *tmp;
	char *res;

	res = ft_strjoin(str, fst);
	tmp = res;
	res = ft_strjoin(res, scd);
	free(tmp);
	return (res);
}

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
	ft_strdel(str);
	ft_strdel(&to_join);
	return (res);
}

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
