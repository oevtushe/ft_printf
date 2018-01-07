#include "ft_printf_helpers.h"

char	*align(char **sv, t_format *sfmt)
{
	int		len;
	char	*res;

	res = ft_strdup(*sv);
	len = ft_strlen(res);
	if (sfmt->width > len && sfmt->FLAG_MINUS)
		res = spc_string(&res, sfmt->width, ' ', '-');
	else if (sfmt->width > len)
		res = spc_string(&res, sfmt->width, ' ', 0);
	free(*sv);
	return (res);
}
