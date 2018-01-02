#include "ft_printf.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf(argv[1], atol(argv[2]));
	printf("\n");
	printf(argv[1], ft_atoi(argv[2]));
	return (0);
}
