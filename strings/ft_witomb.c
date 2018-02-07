#include "ft_printf_helpers.h"

char	*ft_witomb(wint_t wi)
{
	size_t			len;
	size_t			i;
	size_t			res_idx;
	char			*res;
	unsigned char	*cst;

	len = sizeof(wint_t);
	i = len;
	res_idx = 0;
	cst = (unsigned char *)&wi;
	res = ft_strnew(len);
	if (res)
	{
		while (i--)
			if (cst[i])
				res[res_idx++] = cst[i];
		if (res_idx < len)
			ft_str_realloc(&res, res_idx);
	}
	return (res);
}