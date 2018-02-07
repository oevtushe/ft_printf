#include "ft_printf_helpers.h"

intmax_t	gen_load_unsd(t_format *sfmt)
{
	uintmax_t val;

	if (sfmt->modifier == M_LL)
		val = *((unsigned long long int *)sfmt->data);
	else if (sfmt->modifier == M_L)
		val = *((unsigned long int *)sfmt->data);
	else if (sfmt->modifier == M_H)
		val = *((unsigned int *)sfmt->data);
	else if (sfmt->modifier == M_HH)
		val = *((unsigned int *)sfmt->data);
	else if (sfmt->modifier == M_J)
		val = *((uintmax_t *)sfmt->data);
	else if (sfmt->modifier == M_Z)
		val = *((size_t *)sfmt->data);
	else
		val = *((unsigned int *)sfmt->data);
	return (val);
}
