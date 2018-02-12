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

void		handle_signs(t_format *sfmt, char **res, int sign)
{
	if (sfmt->FLAG_PLUS)
		str_add_prefix(res, '+');
	else if (sfmt->FLAG_SPACE)
		str_add_prefix(res, ' ');
	else if (sign < 0)
		str_add_prefix(res, '-');
}

char		*signed_decimal_manager(t_format *sfmt, size_t *len)
{
	int			sign;
	intmax_t	val;
	uintmax_t	uval;
	char		*res;

	sign = 0;
	if (sfmt->type == T_LDEC)
		sfmt->modifier = M_L;
	val = gen_load_decimal(sfmt);
	if (val > 0 && (sfmt->FLAG_PLUS || sfmt->FLAG_SPACE))
		sign = 1;
	else if (val < 0)
		sign = -1;
	decimal_flag_except(sfmt, (sign < 0));
	uval = (sign < 0) ? (val * -1L) : val;
	res = ft_uimtoa(uval);
	if (sfmt->FLAG_SQUOTE && MB_CUR_MAX > 1)
		group_by_thousands(&res);
	width_and_prec(&res, ft_abs(sign), sfmt);
	handle_signs(sfmt, &res, sign);
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
