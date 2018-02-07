#include "ft_printf_helpers.h"

void	form_value(char **val, int sign, t_format *sfmt)
{
	int len;

	len = ft_strlen(*val);
	decimal_flag_except(sfmt, (sign < 0));
	if (sfmt->precision > len)
		spc_string(val, sfmt->precision, '0', 0);
	else if (sfmt->precision == 0 && *val[0] == '0')
	{
		ft_strdel(val);
		*val = ft_strnew(0);
	}
	else if (sfmt->width > len && sfmt->FLAG_ZERO)
		spc_string(val, sfmt->width - ft_abs(sign), '0', 0);
	if (sfmt->FLAG_PLUS)
		str_add_prefix(val, '+');
	else if (sfmt->FLAG_SPACE)
		str_add_prefix(val, ' ');
	else if (sign < 0)
		str_add_prefix(val, '-');
}
