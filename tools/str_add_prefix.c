#include "ft_tools.h"
#include <stdlib.h>

void		str_add_prefix(char **str, char c)
{
	char	*tmp;
	char	*res;

	res = ft_strnew(1);
	if (res)
	{
		res[0] = c;
		tmp = res;
		res = ft_strjoin(res, *str);
		if (res)
		{
			ft_strdel(str);
			*str = res;
		}
		free(tmp);
	}
}
