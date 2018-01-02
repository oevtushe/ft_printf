#include "ft_tools.h"

char			*ft_ltoa(const long int n)
{
	int sign;
	unsigned long int nn;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1L;
	}
	return (ft_lltoa_hlp(nn, sign));
}
