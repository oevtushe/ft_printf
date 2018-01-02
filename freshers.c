#include "ft_printf_helpers.h"

void	del_simple(void *data, size_t size)
{
	++size;
	free(data);
}
