#include "ft_tools.h"
#include <stdlib.h>

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
