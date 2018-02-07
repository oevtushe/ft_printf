#include "ft_printf_helpers.h"

char		*octal_manager(t_format *sfmt)
{
	uintmax_t	uval;
	char		*res;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	uval = gen_load_unsd(sfmt);
	res = ft_uimtoabase_gen(uval, 0, 8);
	form_value(&res, 0, sfmt);
	align(&res, sfmt);
	return (res);
}
