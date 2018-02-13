#include "ft_printf_helpers.h"

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
	if (sfmt->gdata->type == T_LDEC)
		sfmt->gdata->modifier = M_L;
	val = sfmt->gdata->data.im;
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
