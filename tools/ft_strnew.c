#include "ft_tools.h"
#include <stdlib.h>

char	*ft_strnew(const size_t len)
{
	size_t	i;
	char	*str;

	if (!len)
		return (NULL);
	i = 0;
	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = 0;
	return (str);
}
