#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <stdio.h>

void	mixed_index_tests(void)
{
	ft_printf("Mixed index tests\n\n");
	ft_printf("text %1$.*d\n", 4);
	ft_printf("text %d %1$.*d\n", 4);
	ft_printf("text %d %1$d\n", 4);
	ft_printf("text %% %1$d%d \n", 4);
	ft_printf("text %1$d %3$.*d \n", 4);
	ft_printf("text %1$d %3$+.*d \n", 4);
}

void	decimal_tests(void)
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

void	double_percent_test(void)
{
	ft_printf("Other tests\n\n");
	ft_printf("ft: %%\n");
	printf("lb: %%\n\n");
	ft_printf("ft: %% %d\n", 3);
	printf("lb: %% %d\n", 3);
	ft_printf("ft: %%%%%%%%%% %d\n", 3);
	printf("ft: %%%%%%%%%% %d\n", 3);
}

void	invalid_format_strings_test(void)
{
	ft_printf("Invalid format\n\n");
	ft_printf("ft: %\n");
	ft_printf("ft: %test%\n");
	ft_printf("ft: %+03.4%\n");
	ft_printf("ft: %+03.4k\n");
	ft_printf("ft: %+03.-4d\n");
	ft_printf("ft: %+03-.4d\n");
	ft_printf("ft: %0$d\n", 3);
	ft_printf("ft: %1$.*0$d\n", 3);
	ft_printf("ft: %.4.3d\n", 1);
	ft_printf("ft: %hC\n\n", L'🚣');
	ft_printf("ft: %+-0C\n", L'🚣');
	ft_printf("ft: lol%.3cbol\n", '*');
}

void	dollars_test(void)
{
	ft_printf("Dollars test\n\n");
	ft_printf("ft: %1$d\n", 3);
	printf("lb: %1$d\n\n", 3);
	ft_printf("ft: %1$d %1$d\n", 3);
	printf("lb: %1$d %1$d\n\n", 3);
	ft_printf("ft: %1$.*1$d %1$d\n", 3);
	printf("lb: %1$.*1$d %1$d\n\n", 3);
	ft_printf("ft: %1$.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$.*1$d %2$.*1$d\n\n", 3, 4);
	ft_printf("ft: %1$+.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$+.*1$d %2$.*1$d\n\n", 3, 4);
	ft_printf("ft: %1$010.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$010.*1$d %2$.*1$d\n\n", 3, 4);
}

void	asterisk_tests(void)
{
	ft_printf("Asterisk tests\n\n");
	ft_printf("ft: %*d\n", 3, 4);
	printf("lb: %*d\n\n", 3, 4);
	ft_printf("ft: %.*d\n", 3, 4);
	printf("lb: %.*d\n\n", 3, 4);
	ft_printf("ft: %.*d\n", 3, 4);
	printf("lb: %.*d\n\n", 3, 4);
	ft_printf("ft: % .*d\n", 3, 4);
	printf("lb: % .*d\n\n", 3, 4);
	ft_printf("ft: %08.*d\n", 3, 4);
	printf("lb: %08.*d\n\n", 3, 4);
	ft_printf("ft: %*.*d\n", 3, 5, 4);
	printf("lb: %*.*d\n\n", 3, 5, 4);
	ft_printf("ft: %**.*d\n", 3, 4);
	ft_printf("ft: %*****.*d\n", 3, 4);
	ft_printf("ft: %*.**d\n", 3, 4);
	ft_printf("ft: %*.8*d\n", 3, 4);
	//printf("lb: %**.*d\n\n", 3, 4);
}

void	decimals_tests(void)
{
	ft_printf("Decimal tests\n\n");

	ft_printf("ft: %d\n", 3);
	printf("lb: %d\n\n", 3);

	ft_printf("ft: %+d\n", 3);
	printf("lb: %+d\n\n", 3);

	ft_printf("ft: %3d\n", 3);
	printf("lb: %3d\n\n", 3);

	ft_printf("ft: %-3d\n", 3);
	printf("lb: %-3d\n\n", 3);

	ft_printf("ft: %+3d\n", 3);
	printf("lb: %+3d\n\n", 3);

	ft_printf("ft: %+3d\n", -3);
	printf("lb: %+3d\n\n", -3);

	ft_printf("ft: % 3d\n", -3);
	printf("lb: % 3d\n\n", -3);

	ft_printf("ft: %.3d\n", 3);
	printf("lb: %.3d\n\n", 3);

	ft_printf("ft: %.3d\n", -3);
	printf("lb: %.3d\n\n", -3);

	ft_printf("ft: %.d\n", -3);
	printf("lb: %.d\n\n", -3);

	ft_printf("ft: %.d\n", 0);
	printf("lb: %.d\n\n", 0);

	ft_printf("ft: %- 4d\n", 3);
	printf("lb: %- 4.d\n\n", 3);

	ft_printf("ft: %8.4d\n", 3);
	printf("lb: %8.4d\n\n", 3);

	ft_printf("ft: %08.4d\n", 3);
	printf("lb: %08.4d\n\n", 3);

	ft_printf("ft: %03.2d\n", 3);
	printf("lb: %03.2d\n\n", 3);

	ft_printf("ft: %++04.2d\n", INT_MAX);
	printf("lb: %++04.2d\n\n", INT_MAX);

	ft_printf("ft: %00.2d\n", INT_MAX);
	printf("lb: %00.2d\n\n", INT_MAX);

	ft_printf("ft: %00.2d\n", INT_MIN);
	printf("lb: %00.2d\n\n", INT_MIN);

	ft_printf("ft: %40lld\n", LONG_LONG_MAX);
	printf("lb: %40lld\n\n", LONG_LONG_MAX);
}

void	decimal_grouping_tests(void)
{
	ft_printf("Decimal grouping\n\n");
	ft_printf("ft: %'d\n", INT_MIN);
	printf("lb: %'d\n\n", INT_MIN);
}

void	wchar_tests(void)
{
	ft_printf("Wchar's tests\n\n");
	ft_printf("ft: %lc\n", (wint_t)9787);
	printf("lb: %lc\n\n", (wint_t)9787);

	ft_printf("ft: %lc\n", L'🚣');
	printf("lb: %lc\n\n", L'🚣');

	ft_printf("ft: %C\n", L'🚣');
	printf("lb: %C\n\n", L'🚣');

	ft_printf("ft: %C\n", L'🚣');
	printf("lb: %C\n\n", L'🚣');

	ft_printf("ft: %18C\n", L'🚣');
	printf("lb: %18C\n\n", L'🚣');

	ft_printf("ft: %C\n", L'Р');
	printf("lb: %C\n\n", L'Р');

	ft_printf("ft: %C\n", L'z');
	printf("lb: %C\n\n", L'z');
}

void	str_tests(void)
{
	ft_printf("Str's tests\n\n");

	ft_printf("ft: %s\n", "hello");
	printf("lb: %s\n\n", "hello");

	ft_printf("ft: %10s\n", "hello");
	printf("lb: %10s\n\n", "hello");

	ft_printf("ft: %.10s\n", "hello");
	printf("lb: %.10s\n\n", "hello");

	ft_printf("ft: %.1s\n", "hello");
	printf("lb: %.1s\n\n", "hello");

	ft_printf("ft: %.s\n", "hello");
	printf("lb: %.s\n\n", "hello");

	ft_printf("ft: %.s\n", "hello");
	printf("lb: %.s\n\n", "hello");

	ft_printf("ft: %-10s\n", "hello");
	printf("lb: %-10s\n\n", "hello");

	ft_printf("ft: hi %-10s yep\n", "hello");
	printf("lb: hi %-10s yep\n\n", "hello");

	ft_printf("ft: hi %10.2s yep\n", "hello");
	printf("lb: hi %10.2s yep\n\n", "hello");
}

void	wstr_tests(void)
{
	ft_printf("Wstr's tests\n\n");

	ft_printf("ft: %ls\n", L"🚖 here is");
	printf("lb: %ls\n\n", L"🚖 here is");

	ft_printf("ft: %S\n", L"🚖 here is");
	printf("lb: %S\n\n", L"🚖 here is");

	ft_printf("ft: %30ls\n", L"🚖 here is");
	printf("lb: %30ls\n\n", L"🚖 here is");

	ft_printf("ft: %3ls\n", L"🚖 here is");
	printf("lb: %3ls\n\n", L"🚖 here is");

	ft_printf("ft: %.3ls\n", L"🚖 here is");
	printf("lb: %.3ls\n\n", L"🚖 here is");

	ft_printf("ft: %.4ls\n", L"🚖 here is");
	printf("lb: %.4ls\n\n", L"🚖 here is");

	ft_printf("ft: %.9ls\n", L"🚖 here is");
	printf("lb: %.9ls\n\n", L"🚖 here is");
}

void	chr_tests(void)
{
	ft_printf("Chr's tests\n\n");

	ft_printf("ft: %c\n", 42);
	printf("lb: %c\n\n", 42);

	ft_printf("ft: %10c\n", 42);
	printf("lb: %10c\n\n", 42);

	ft_printf("ft: %10c\n", 0);
	printf("lb: %10c\n\n", 0);

	ft_printf("ft: %-10c\n", 0);
	printf("lb: %-10c\n\n", 0);

	ft_printf("ft: %c\n", 0);
	printf("lb: %c\n\n", 0);

	ft_printf("ft: lol%cbol\n", 0);
	printf("lb: lol%cbol\n\n", 0);
}

int	main(void)
{
	setlocale(LC_ALL, "");
	mixed_index_tests();
	ft_printf("\n");
	decimal_tests();
	ft_printf("\n");
	double_percent_test();
	ft_printf("\n");
	invalid_format_strings_test();
	ft_printf("\n");
	dollars_test();
	ft_printf("\n");
	asterisk_tests();
	ft_printf("\n");
	decimals_tests();
	ft_printf("\n");
	decimal_grouping_tests();
	ft_printf("\n");
	wchar_tests();
	ft_printf("\n");
	str_tests();
	ft_printf("\n");
	wstr_tests();
	ft_printf("\n");
	chr_tests();
	return (0);
}