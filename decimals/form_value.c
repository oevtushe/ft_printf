#include "ft_printf_helpers.h"

char	*form_value(uintmax_t val, int sign, t_format *sfmt)
{
	char			*res;
	int				len;

	decimal_flag_except(sfmt, (sign < 0));
	res = ft_uimtoa(val);
	len = ft_strlen(res);
	if (sfmt->precision > len)
		res = spc_string(&res, sfmt->precision, '0', 0);
	else if (sfmt->precision == 0 && res[0] == '0')
	{
		free(res);
		res = ft_strnew(0);
	}
	else if (sfmt->width > len && sfmt->FLAG_ZERO)
		res = spc_string(&res, sfmt->width - ft_abs(sign), '0', 0);
	if (sfmt->FLAG_PLUS)
		res = str_add_prefix(&res, '+');
	else if (sfmt->FLAG_SPACE)
		res = str_add_prefix(&res, ' ');
	else if (sign < 0)
		res = str_add_prefix(&res, '-');
	return (res);
}
