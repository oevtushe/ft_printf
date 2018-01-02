#include "ft_tools.h"

char			*ft_lltoa(const long long int n)
{
	int sign;
	unsigned long long int nn;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1LL;
	}
	return (ft_lltoa_hlp(nn, sign));
}
