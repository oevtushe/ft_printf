#include "ft_printf_helpers.h"

char		*octal_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	decimal_flag_except(sfmt, 0);
	uval = gen_load_unsd(sfmt);
	res = ft_uimtoabase_gen(uval, 0, 8);
	width_and_prec(&res, 0, sfmt);
	if (sfmt->FLAG_SHARP && res[0] != '0')
		str_add_prefix(&res, '0');
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
