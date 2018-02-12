#include "ft_printf_helpers.h"

DATA_LOADER(intmax_t, jd)
DATA_LOADER(long long int, lld)
DATA_LOADER(long int, ld)
DATA_LOADER(ssize_t, zd)
DATA_LOADER(int, d)

void	*signed_decimal_modifiers(char *str, va_list ap)
{
	int		*tmp;
	void	*data;

	data = NULL;
	if (str[0] == 'l' && str[1] == 'l')
		data = load_lld(ap);
	else if (str[0] == 'l' || str[0] == T_LDEC)
		data = load_ld(ap);
	else if (str[0] == 'h')
	{
		tmp = (int *)load_d(ap);
		if (str[1] == 'h')
			*tmp = (char)*tmp;
		else
			*tmp = (short)*tmp;
		data = tmp; 
	}
	else if (str[0] == 'j')
		data = load_jd(ap);
	else if (str[0] == 'z')
		data = load_zd(ap);
	else
		data = load_d(ap);
	return (data);
}
