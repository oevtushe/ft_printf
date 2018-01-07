#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

int		main(int argc, char **argv)
{
	size_t a;
	if (argc != 3)
		return (1);

	a = atoi(argv[2]);
	ft_printf(argv[1], a);
	printf("\n");
	printf(argv[1], a);
	return (0);
}
