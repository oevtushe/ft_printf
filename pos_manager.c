#include "ft_printf_helpers.h"

char	*pos_manager(t_format *sfmt, int len)
{
	if (sfmt->MODIFIER_l)
		*(long int *)sfmt->data = len;	
	else if (sfmt->MODIFIER_ll)
		*(long long int *)sfmt->data = len;	
	else if (sfmt->MODIFIER_h)
		*(short int *)sfmt->data = len;	
	else if (sfmt->MODIFIER_hh)
		*(char *)sfmt->data = len;	
	else if (sfmt->MODIFIER_j)
		*(intmax_t *)sfmt->data = len;	
	else if (sfmt->MODIFIER_z)
		*(ssize_t *)sfmt->data = len;	
	else
		*(int *)sfmt->data = len;
	sfmt->data = NULL;
	return (ft_strnew(0));
}
