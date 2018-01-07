#include "ft_printf_helpers.h"

char	*init_types(void)
{
	char *res;

	res = ft_strnew(3);
	res[0] = 's';
	res[1] = 'd';
	res[2] = 'f';
	return (res);
}
