#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("%lc\n", L'л');
	printf("%lc\n", L'л');
	//printf("%");
	//system("leaks main");
	return (0);
}