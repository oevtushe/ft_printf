#include "ft_tools.h"

char	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	res = NULL;
	if (s1 && s2)
	{
		len1 = ft_wstrlen(s1);
		len2 = ft_wstrlen(s2);
		res = ft_strnew((len1 + len2) * sizeof(wchar_t));
		if (res)
		{
			ft_memcpy(res, s1, len1);
			ft_memcpy(res + len1, s2, len2);
		}
	}
	return (res);
}
