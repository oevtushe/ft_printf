#include "ft_printf_helpers.h"

static void	decimal_flag_except(t_format *sfmt)
{
	if (sfmt->FLAG_MINUS && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->precision >= 0 && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->FLAG_PLUS && sfmt->FLAG_SPACE)
		sfmt->FLAG_SPACE = 0;
}

static char	*decimal_cast(t_format *sfmt, const int val, char *val_str)
{
	char	*res;
	int		len;

	res = ft_strdup(val_str);
	len = ft_strlen(res);
	decimal_flag_except(sfmt);
	if (sfmt->precision > len)
		res = spc_string(&res, (len = sfmt->precision), '0', 0);
	if (sfmt->width > len && sfmt->FLAG_ZERO)
	{
		len = sfmt->width;
		if ((sfmt->FLAG_PLUS || sfmt->FLAG_SPACE) && val >= 0)
			--len;
		res = spc_string(&res, len, '0', 0);
	}
	if (sfmt->FLAG_PLUS && val >= 0)
		res = str_add_prefix(&res, &len, '+');
	if (sfmt->FLAG_SPACE && val >= 0)
		res = str_add_prefix(&res, &len, ' ');
	if (sfmt->width > len && sfmt->FLAG_MINUS)
		res = spc_string(&res, (len = sfmt->width), ' ', '-');
	if (sfmt->width > len)
		res = spc_string(&res, (len = sfmt->width), ' ', 0);
	return (res);
}

char	*decimal_manager(va_list ap, t_format *sfmt)
{
	char *res;
	char *str;

	res = NULL;
	/*
	if (ft_strcmp(sfmt->modifiers, MODIFIER_l))
	if (ft_strcmp(sfmt->modifiers, MODIFIER_ll))
	if (ft_strcmp(sfmt->modifiers, MODIFIER_h))
	if (ft_strcmp(sfmt->modifiers, MODIFIER_hh))
	else
	*/
	if (sfmt->MODIFIER_l)
		str = ft_ltoa(va_arg(ap, long int));
	else
		str = ft_itoa(va_arg(ap, int));
		res = decimal_manager_simple(sfmt, va_arg(ap, int));
	res = decimal_manager(sfmt, str);
	free(str);
	return (res);
}
