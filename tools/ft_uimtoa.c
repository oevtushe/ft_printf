#include "ft_printf_helpers.h"

char			*ft_uimtoa(const uintmax_t n)
{
	return (ft_uimtoa_hlp(n, 1));
}
