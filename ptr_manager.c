#include "ft_printf_helpers.h"

char	*ptr_manager(t_format *sfmt, size_t *len)
{
	char	*res;
	char	*tmp;
	size_t	val;

	val = (size_t)sfmt->gdata->data.pv;
	res = ft_uimtoabase_gen(val, 0, 16);
	if (res)
	{
		width_and_prec(&res, 0, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		align(&res, sfmt);
		ft_strdel(&tmp);
	}
	*len = ft_strlen(res);
	return (res);
}
