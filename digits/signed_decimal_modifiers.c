#include "ft_printf_helpers.h"

void	signed_decimal_modifiers(char *str, va_list ap, t_gdata *gdata)
{
	if (str[0] == 'l' && str[1] == 'l')
		load_lld(gdata, ap);
	else if (str[0] == 'l' || str[0] == T_LDEC)
		load_ld(gdata, ap);
	else if (str[0] == 'h' && str[1] == 'h')
		load_hhd(gdata, ap);
	else if (str[0] == 'h')
		load_hd(gdata, ap);
	else if (str[0] == 'j')
		load_jd(gdata, ap);
	else if (str[0] == 'z')
		load_zd(gdata, ap);
	else
		load_d(gdata, ap);
}
