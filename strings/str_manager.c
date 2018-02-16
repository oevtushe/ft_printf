#include "ft_printf_helpers.h"

/* sfmt->precision >= 0 like in man (str may not have term. zero) */
char		*str_manager(t_format *sfmt, size_t *ln)
{
	char	*res;

	if ((sfmt->gdata->modifier == M_L || sfmt->gdata->type == T_WSTR)
			&& MB_CUR_MAX > 1)
		res = wcs_to_utf8(sfmt->gdata->data.pwc, sfmt->precision);
	else
	{
		if (sfmt->precision >= 0)
		{
			res = ft_strnew(sfmt->precision);
			ft_memcpy(res, sfmt->gdata->data.pc, sfmt->precision);
		}
		else
			ft_strdup(sfmt->gdata->data.pc);
	}
	align(&res, sfmt);
	*ln = ft_strlen(res);
	return (res);
}
