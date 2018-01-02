#include "ft_tools.h"
#include <stdlib.h>

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

