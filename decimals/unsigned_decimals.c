#include "ft_printf_helpers.h"

static  intmax_t	gen_load_unsd(t_format *sfmt)
{
	uintmax_t val;

	if (sfmt->MODIFIER_ll)
		val = *((unsigned long long int *)sfmt->data);
	else if (sfmt->MODIFIER_l)
		val = *((unsigned long int *)sfmt->data);
	else if (sfmt->MODIFIER_h)
		val = *((unsigned int *)sfmt->data);
	else if (sfmt->MODIFIER_hh)
		val = *((unsigned int *)sfmt->data);
	else if (sfmt->MODIFIER_j)
		val = *((uintmax_t *)sfmt->data);
	else if (sfmt->MODIFIER_z)
		val = *((size_t *)sfmt->data);
	else
		val = *((unsigned int *)sfmt->data);
	return (val);
}

char		*unsigned_decimal_manager(t_format *sfmt)
{
	uintmax_t	uval;
	char		*res;

	sfmt->FLAG_PLUS = 0;
	uval = gen_load_unsd(sfmt);
	res = form_value(uval, 0, sfmt);
	res = align(&res, sfmt);
	return (res);
}
