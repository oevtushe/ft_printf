#include "ft_tools.h"

static int		ft_intln_help(unsigned long long int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_intln_help(n / 10));
}

static int		ft_intln(unsigned long long int n, int sign)
{
	int			extra;

	extra = 0;
	if (sign < 0)
		extra = 1;
	return (extra + ft_intln_help(n));
}

static void		ft_itoa_help(unsigned long long int n, char *str, int *idx)
{
	if (n <= 9)
	{
		str[(*idx)++] = n + '0';
		return ;
	}
	ft_itoa_help(n / 10, str, idx);
	str[(*idx)++] = (n % 10) + '0';
}

char		*ft_lltoa_hlp(const unsigned long long int n, int sign)
{
	char					*res;
	int						idx;

	idx = 0;
	res = ft_strnew(ft_intln(n, sign));
	if (res)
	{
		if (sign < 0)
			res[idx++] = '-';
		ft_itoa_help(n, res, &idx);
	}
	return (res);
}