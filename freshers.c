#include "ft_printf.h"

void	del_simple(void *data, size_t size)
{
	++size;
	free(data);
}
