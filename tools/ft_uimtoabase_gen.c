#include "ft_tools.h"

static int	val_len(uintmax_t val)
{
	if (val < 10)
		return (1);
	return (1 + val_len(val / 10));
}

static char	get_chr(uintmax_t val)
{
	if (val < 10)
		return (val + '0');
	return (val - 10 + 'a');
}

static void	ft_itoa_hlp(uintmax_t val, int base, char *res, int *idx)
{
	if (val < (uintmax_t)base)
		res[(*idx)++] = get_chr(val);
	else
	{
		ft_itoa_hlp(val / base, base, res, idx);
		res[(*idx)++] = get_chr(val % base);
	}
}

char		*ft_uimtoabase_gen(uintmax_t val, int sign, int base)
{
	char	*res;
	int		idx;

	idx = 0;
	res = NULL;
	if (base > 1 && base < 17)
	{
		if (sign && base == 10)
		{
			res = ft_strnew(val_len(val) + 1);
			res[idx++] = '-';
		}
		else
			res = ft_strnew(val_len(val));
		ft_itoa_hlp(val, base, res, &idx);
	}
	return (res);
}
