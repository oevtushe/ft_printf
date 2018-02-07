#include "ft_tools.h"

char	*ft_imtoabase(intmax_t val, unsigned int base)
{
	int			sign;
	uintmax_t	uval;

	sign = 0;
	if (val < 0)
	{
		uval = val * -1L;
		if (base == 10)
			sign = 1;
	}
	else
		uval = val;
	return (ft_uimtoabase_gen(uval, sign, base));
}
