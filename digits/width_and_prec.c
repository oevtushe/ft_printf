#include "ft_printf_helpers.h"

void	width_and_prec(char **val, int prefix, t_format *sfmt)
{
	int len;

	len = ft_strlen(*val);
	if (sfmt->precision > len)
		spc_string(val, sfmt->precision, '0', 0);
	else if (sfmt->precision == 0 && *val[0] == '0')
	{
		ft_strdel(val);
		*val = ft_strnew(0);
	}
	else if (sfmt->width > len && sfmt->FLAG_ZERO)
		spc_string(val, sfmt->width - prefix, '0', 0);
}
