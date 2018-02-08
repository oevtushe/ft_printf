#include "ft_printf_helpers.h"

char	*ptr_manager(t_format *sfmt)
{
	char	*res;
	char	*tmp;
	size_t	val;

	val = (size_t)sfmt->data;
	sfmt->data = NULL;
	res = ft_uimtoabase_gen(val, 0, 16);
	if (res)
	{
		width_and_prec(&res, 0, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		align(&res, sfmt);
		ft_strdel(&tmp);
	}
	return (res);
}
