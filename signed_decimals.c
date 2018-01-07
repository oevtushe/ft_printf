#include "ft_printf_helpers.h"

static char	*form_value_im(intmax_t val, t_format *sfmt)
{
	int			sign;
	uintmax_t	uval;
	char		*res;

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

char		*signed_decimal_manager(va_list ap, t_format *sfmt)
{
	char *res;

	res = NULL;
	if (sfmt->MODIFIER_l)
		res = form_value_im(va_arg(ap, long int), sfmt);
	else if (sfmt->MODIFIER_ll)
		res = form_value_im(va_arg(ap, long long int), sfmt);
	else if (sfmt->MODIFIER_j)
		res = form_value_im(va_arg(ap, intmax_t), sfmt);
	else if (sfmt->MODIFIER_z)
		res = form_value_im(va_arg(ap, ssize_t), sfmt);
	else
		res = form_value_im(va_arg(ap, int), sfmt);
	return (res);
}
