#include "ft_printf_helpers.h"

/* sfmt->precision >= 0 like in man (str may not have term. zero) */
char		*str_manager(t_format *sfmt, size_t *ln)
{
	int		len;
	char	*res;

	if (sfmt->gdata->modifier == M_L || sfmt->gdata->type == T_WSTR)
		res = wcs_to_utf8(sfmt->gdata->data.pwc);
	else
		res = ft_strdup(sfmt->gdata->data.pc);
	len = ft_strlen(res);
	if (sfmt->precision >= 0 && sfmt->precision < len)
		ft_str_realloc(&res, sfmt->precision);
	align(&res, sfmt);
	*ln = ft_strlen(res);
	return (res);
}
