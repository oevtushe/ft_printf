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

char		*wcs_to_utf8(wchar_t *wcs, int len)
{
	char			*res;
	char			*dp;
	wint_t			utf;
	int				sum_len;
	int				cnt;

	res = ft_strnew(0);
	sum_len = 0;
	cnt = -1;
	while (sum_len < len && wcs[++cnt])
	{
		utf = unicode_to_utf8(wcs[cnt]);
		dp = ft_witomb(utf);
		sum_len += ft_strlen(dp);
		if (sum_len > len)
		{
			ft_strdel(&dp);
			break ;
		}
		strconnect(&res, dp);
		ft_strdel(&dp);
	}
	return (res);
}
