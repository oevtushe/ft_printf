#include "ft_printf_helpers.h"

void	ft_strtoupper(char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= ' ';
			++i;
		}
	}
}
