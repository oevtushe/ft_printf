#include "ft_tools.h"
#include <stdlib.h>

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
