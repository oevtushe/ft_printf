#include "libft.h"
#include <stdio.h>
#include <wchar.h>

int		unicode_to_utf8(wchar_t val);

int		main(void)
{
	int		val;
	int		res;

	val = 0x10348;
	printf("val: %s\n", ft_itoabase(val, 2));
	res = unicode_to_utf8(val);
	printf("res: %s\n", ft_itoabase(res, 2));
	return (0);
}
