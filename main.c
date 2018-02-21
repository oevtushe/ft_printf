#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <stdio.h>

void	mixed_index_tests()
{
	ft_printf("Mixed index tests\n\n");
	ft_printf("text %1$.*d\n", 4);
	ft_printf("text %d %1$.*d\n", 4);
	ft_printf("text %d %1$d\n", 4);
	ft_printf("text %% %1$d%d \n", 4);
	ft_printf("text %1$d %3$.*d \n", 4);
	ft_printf("text %1$d %3$+.*d \n", 4);
}

void	decimal_tests()
{
	ft_printf("Decimal tests\n\n");
	ft_printf("ft: %d\n", 8);
	printf("lb: %d\n\n", 8);
	ft_printf("ft: %d%d\n", 8, 3);
	printf("lb: %d%d\n\n", 8, 3);
	ft_printf("ft: %3d%d\n", 8, 3);
	printf("lb: %3d%d\n\n", 8, 3);
	ft_printf("ft: %-3d%d\n", 8, 3);
	printf("lb: %-3d%d\n", 8, 3);
}

void	double_percent_test()
{
	ft_printf("Other tests\n\n");
	ft_printf("ft: %%\n");
	printf("lb: %%\n\n");
	ft_printf("ft: %% %d\n", 3);
	printf("lb: %% %d\n", 3);
	ft_printf("ft: %%%%%%%%%% %d\n", 3);
	printf("ft: %%%%%%%%%% %d\n", 3);
}

void	invalid_format_strings_test()
{
	ft_printf("Invalid format\n\n");
	ft_printf("ft: %\n");
	ft_printf("ft: %test%\n");
	ft_printf("ft: %+03.4%\n");
	ft_printf("ft: %+03.4k\n");
	ft_printf("ft: %+03.-4d\n");
	ft_printf("ft: %+03-.4d\n");
}

int	main(void)
{
	mixed_index_tests();
	ft_printf("\n");
	decimal_tests();
	ft_printf("\n");
	double_percent_test();
	ft_printf("\n");
	invalid_format_strings_test();
	return (0);
}