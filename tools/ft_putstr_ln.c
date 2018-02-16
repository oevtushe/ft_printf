#include "ft_tools.h"

void	ft_putstr_ln(const char *str, size_t len)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (i < len)
			write(1, &str[i++], 1);
	}
}
