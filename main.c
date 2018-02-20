#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	//ft_printf("%1$d", 1);
	ft_printf("text %d\n", 4);
	// ft_printf("before %O after", 42);
	// ft_printf("%O%O%O%O%O", 1, 100, 999, 42, 999988888);
	// ft_printf("a%Ob%Oc%Od", 0, 55555, 100000);
	// ft_printf("%O", LONG_MAX);
	//printf("%");
	//system("leaks main");
	return (0);
}