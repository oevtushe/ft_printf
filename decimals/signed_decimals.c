#include "ft_printf_helpers.h"

static  intmax_t	gen_load_decimal(t_format *sfmt)
{
	intmax_t val;

	if (sfmt->modifier == M_LL)
		val = *((long long int *)sfmt->data);
	else if (sfmt->modifier == M_L)
		val = *((long int *)sfmt->data);
	else if (sfmt->modifier == M_H)
		val = *((int *)sfmt->data);
	else if (sfmt->modifier == M_HH)
		val = *((int *)sfmt->data);
	else if (sfmt->modifier == M_J)
		val = *((intmax_t *)sfmt->data);
	else if (sfmt->modifier == M_Z)
		val = *((ssize_t *)sfmt->data);
	else
		val = *((int *)sfmt->data);
	return (val);
}

char		*signed_decimal_manager(t_format *sfmt)
{
	int			sign;
	intmax_t	val;
	uintmax_t	uval;
	char		*res;

	sign = 0;
	val = gen_load_decimal(sfmt);
	if (val > 0 && (sfmt->FLAG_PLUS || sfmt->FLAG_SPACE))
		sign = 1;
	else if (val < 0)
		sign = -1;
	uval = (sign < 0) ? (val * -1L) : val;
	res = form_value(uval, sign, sfmt);
	res = align(&res, sfmt);
	return (res);
}
