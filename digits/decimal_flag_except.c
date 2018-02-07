#include "ft_printf_helpers.h"

void	decimal_flag_except(t_format *sfmt, int negative)
{
	if (sfmt->FLAG_MINUS && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->precision >= 0 && sfmt->FLAG_ZERO)
		sfmt->FLAG_ZERO = 0;
	if (sfmt->FLAG_PLUS && sfmt->FLAG_SPACE)
		sfmt->FLAG_SPACE = 0;
	if (negative && sfmt->FLAG_PLUS)
		sfmt->FLAG_PLUS = 0;
	if (negative && sfmt->FLAG_SPACE)
		sfmt->FLAG_SPACE = 0;
}
