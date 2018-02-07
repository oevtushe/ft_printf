#include "ft_printf_helpers.h"

/* sfmt->precision >= 0 like in man (str may not have term. zero) */
char		*str_manager(t_format *sfmt)
{
	int		len;
	char	*res;

	if (sfmt->modifier == M_L || sfmt->type == T_WSTR)
		res = wcs_to_utf8(sfmt->data);
	else
		res = ft_strdup(sfmt->data);
	len = ft_strlen(res);
	sfmt->data = NULL;
	if (sfmt->precision >= 0 && sfmt->precision < len)
		ft_str_realloc(&res, sfmt->precision);
	align(&res, sfmt);
	return (res);
}
