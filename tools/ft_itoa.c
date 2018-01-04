#include "ft_tools.h"

char			*ft_itoa(const int n)
{
	int sign;
	unsigned int nn;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1L;
	}
	else
		nn = n;
	return (ft_uimtoa_hlp(nn, sign));
}
