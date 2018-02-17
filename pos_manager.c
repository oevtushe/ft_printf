#include "ft_printf_helpers.h"

char	*pos_manager(t_format *sfmt, int len, size_t *ln)
{
	if (sfmt->gdata->full_type->modifier == M_L)
		*(long int *)sfmt->gdata->data.pv = len;	
	else if (sfmt->gdata->full_type->modifier == M_LL)
		*(long long int *)sfmt->gdata->data.pv = len;	
	else if (sfmt->gdata->full_type->modifier == M_H)
		*(short int *)sfmt->gdata->data.pv = len;	
	else if (sfmt->gdata->full_type->modifier == M_HH)
		*(char *)sfmt->gdata->data.pv= len;	
	else if (sfmt->gdata->full_type->modifier == M_J)
		*(intmax_t *)sfmt->gdata->data.pv = len;	
	else if (sfmt->gdata->full_type->modifier == M_Z)
		*(ssize_t *)sfmt->gdata->data.pv = len;	
	else
		*(int *)sfmt->gdata->data.pv = len;
	*ln = 0;
	return (ft_strnew(0));
}
