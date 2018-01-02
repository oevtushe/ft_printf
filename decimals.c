#include "ft_printf_helpers.h"

static void	decimal_flag_except(t_format *sfmt, int negative)
{
	if (sfmt->FLAG_MINUS && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->precision >= 0 && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->FLAG_PLUS && sfmt->FLAG_SPACE)
		sfmt->FLAG_SPACE = 0;
	if (negative && sfmt->FLAG_PLUS)
		sfmt->FLAG_PLUS = 0;
	if (negative && sfmt->FLAG_SPACE)
		sfmt->FLAG_SPACE = 0;
}

int		abs(int val)
{
	return ((val > 0 ) ? val : -val);
}

char	*form_value(unsigned long long int val, int sign, t_format *sfmt)
{
	char			*res;
	int				len;

	decimal_flag_except(sfmt, (sign < 0));
	res = ft_ulltoa(val);
	len = ft_strlen(res);
	if (sfmt->precision > len)
		res = spc_string(&res, sfmt->precision, '0', 0);
	else if (sfmt->width > len && sfmt->FLAG_ZERO)
		res = spc_string(&res, sfmt->width - abs(sign), '0', 0);
	if (sfmt->FLAG_PLUS)
		res = str_add_prefix(&res, '+');
	else if (sfmt->FLAG_SPACE)
		res = str_add_prefix(&res, ' ');
	else if (sign < 0)
		res = str_add_prefix(&res, '-');
	return (res);
}

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

char	*form_value_ll(long long int val, t_format *sfmt)
{
	int						sign;
	unsigned long long int	uval;
	char					*res;

	if (val > 0 && (sfmt->FLAG_PLUS || sfmt->FLAG_SPACE))
		sign = 1;
	else if (val < 0)
		sign = -1;
	else
		sign = 0;
	uval = (sign < 0) ? (val * -1L) : val;
	res = form_value(uval, sign, sfmt);
	res = align(&res, sfmt);
	return (res);
}

char	*decimal_manager(va_list ap, t_format *sfmt)
{
	char *res;

	res = NULL;
	if (sfmt->MODIFIER_l)
		res = form_value_ll(va_arg(ap, long int), sfmt);
	else if (sfmt->MODIFIER_ll)
		res = form_value_ll(va_arg(ap, long long int), sfmt);
	else
		res = form_value_ll(va_arg(ap, int), sfmt);
	return (res);
}
