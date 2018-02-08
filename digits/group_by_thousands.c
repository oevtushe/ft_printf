#include "ft_printf_helpers.h"

void	group_by_thousands(char **val)
{
	size_t	old_len;
	char	*nstr;
	size_t	ostr_idx;
	size_t	nstr_idx;

	old_len = ft_strlen(*val);
	nstr = ft_strnew(old_len + ((old_len - 1) / 3) * 2);
	nstr_idx = old_len + ((old_len - 1) / 3) * 2;
	ostr_idx = old_len;
	while (ostr_idx--)
	{
		nstr[--nstr_idx] = (*val)[ostr_idx];
		if (nstr_idx && (old_len - ostr_idx) % 3 == 0)
		{
			nstr[--nstr_idx] = 0xA0;
			nstr[--nstr_idx] = 0xC2;
		}
	}
	ft_strdel(val);
	*val = nstr;
}
