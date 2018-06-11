#include "ft_printf_helpers.h"

/*
** Function works like ft_printf, except printing
** string in the end it returns it.
**
** @param	len		placeholder for future string
**					length.
** @param	format	format of future string.
*/

char	*ft_format(const char *format, size_t *len, ...)
{
	va_list ap;
	char	*str;

	str = NULL;
	if (format && len)
	{
		*len = 0;
		va_start(ap, len);
		str = mk_format(format, ap, len);
		va_end(ap);
	}
	return (str);
}
