#include "ft_printf_helpers.h"

char	*ptr_manager(t_format *sfmt)
{
	char	*res;
	char	*tmp;
	size_t	val;
	int		sign;

	val = (size_t)sfmt->data;
	sfmt->data = NULL;
	sign = sfmt->FLAG_PLUS ? 1 : 0;
	res = ft_uimtoabase_gen(val, 0, 16);
	if (res)
	{
		form_value(&res, sign, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		align(&res, sfmt);
		ft_strdel(&tmp);
	}
	return (res);
}
