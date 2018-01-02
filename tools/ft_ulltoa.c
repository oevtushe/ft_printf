#include "ft_tools.h"

char			*ft_ulltoa(const unsigned long long int n)
{
	return (ft_lltoa_hlp(n, 1));
}
