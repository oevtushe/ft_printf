#include "ft_printf_helpers.h"

char	*pos_manager(t_format *sfmt, int len)
{
	if (sfmt->modifier == M_L)
		*(long int *)sfmt->data = len;	
	else if (sfmt->modifier == M_LL)
		*(long long int *)sfmt->data = len;	
	else if (sfmt->modifier == M_H)
		*(short int *)sfmt->data = len;	
	else if (sfmt->modifier == M_HH)
		*(char *)sfmt->data = len;	
	else if (sfmt->modifier == M_J)
		*(intmax_t *)sfmt->data = len;	
	else if (sfmt->modifier == M_Z)
		*(ssize_t *)sfmt->data = len;	
	else
		*(int *)sfmt->data = len;
	sfmt->data = NULL;
	return (ft_strnew(0));
}
