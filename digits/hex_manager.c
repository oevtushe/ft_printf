#include "ft_printf_helpers.h"

char		*hex_manager(t_format *sfmt)
{
	uintmax_t	uval;
	char		*res;
	char		*tmp;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	uval = gen_load_unsd(sfmt);
	res = ft_uimtoabase_gen(uval, 0, 16);
	if (sfmt->FLAG_SHARP && uval)
	{
		width_and_prec(&res, 2, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		ft_strdel(&tmp);
	}
	else
		width_and_prec(&res, 0, sfmt);
	if (sfmt->type == T_BHEX)
		ft_strtoupper(res);
	align(&res, sfmt);
	return (res);
}
