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
	ft_printf("text %08% %3$+.*d \n", 4);
}

void	invalid_format_strings_test(void)
{
	ft_printf("Invalid format\n\n");
	ft_printf("ft: %\n");
	ft_printf("ft: %test%\n");
	ft_printf("ft: %+03.4k\n");
	ft_printf("ft: %+03.-4d\n");
	ft_printf("ft: %+03-.4d\n");
	ft_printf("ft: %0$d\n", 3);
	ft_printf("ft: %1$.*0$d\n", 3);
	ft_printf("ft: %.4.3d\n", 1);
	ft_printf("ft: %hC\n\n", L'🚣');
	ft_printf("ft: %+-0C\n", L'🚣');
	ft_printf("ft: lol%.3cbol\n", '*');
	ft_printf("ft: %**.*d\n", 3, 4);
	ft_printf("ft: %*****.*d\n", 3, 4);
	ft_printf("ft: %*.**d\n", 3, 4);
	ft_printf("ft: %*.8*d\n", 3, 4);
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

	ft_printf("ft: %1$.*1$d %1$d\n", -3);
	printf("lb: %1$.*1$d %1$d\n\n", -3);

	ft_printf("ft: %1$.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$.*1$d %2$.*1$d\n\n", 3, 4);

	ft_printf("ft: %1$+.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$+.*1$d %2$.*1$d\n\n", 3, 4);

	ft_printf("ft: %1$010.*1$d %2$.*1$d\n", 3, 4);
	printf("lb: %1$010.*1$d %2$.*1$d\n\n", 3, 4);

	ft_printf("ft: %08% %1$.*1$d %1$d\n", 3);
	printf("lb: %08% %1$.*1$d %1$d\n\n", 3);

	ft_printf("ft: %1$8% %1$.*1$d %1$d\n", 3);
	printf("lb: %1$8% %1$.*1$d %1$d\n\n", 3);
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

	ft_printf("ft: %*d\n", -3, 4);
	printf("lb: %*d\n\n", -3, 4);
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

	ft_printf("ft: %05d\n", -42);
	printf("lb: %05d\n\n", -42);

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

	ft_printf("ft: %'010d\n", 42);
	printf("lb: %'010d\n\n", 42);
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

void	binary_tests(void)
{
	ft_printf("Binary tests\n\n");

	ft_printf("ft: %b\n", 1024);
	ft_printf("ft: %b\n", 0);
	ft_printf("ft: %b\n", 10);
	ft_printf("ft: %b\n", 127);
	ft_printf("ft: %8b\n", 127);
	ft_printf("ft: %.8b\n", 127);
	ft_printf("ft: %08b\n", 127);
	ft_printf("ft: %-8b\n", 127);
	ft_printf("ft: %0b\n", 127);
	ft_printf("ft: %+b\n", 127);
	ft_printf("ft: % b\n", 127);
	ft_printf("ft: %+b\n", -127);
	ft_printf("ft: % b\n", -127);
	ft_printf("ft: %16b\n", 100);
	ft_printf("ft: %'b\n", 100);
	ft_printf("ft: %'016b\n", 100);
	ft_printf("ft: %'07b\n", 100);
}

void	percent_tests(void)
{
	ft_printf("Percent tests\n\n");

	ft_printf("ft: %06%\n");
	printf("lb: %06%\n\n");

	ft_printf("ft: %.6%\n");
	printf("lb: %.6%\n\n");

	ft_printf("ft: %8.6%\n");
	printf("lb: %8.6%\n\n");

	ft_printf("ft: %08.6%\n");
	printf("lb: %08.6%\n\n");

	ft_printf("ft: %+08.6%\n");
	printf("lb: %+08.6%\n\n");

	ft_printf("ft: %-08.6%\n");
	printf("lb: %-08.6%\n\n");

	ft_printf("ft: %-08.6%\n");
	printf("lb: %-08.6%\n\n");

	ft_printf("ft: %%\n");
	printf("lb: %%\n\n");

	ft_printf("ft: %% %d\n", 3);
	printf("lb: %% %d\n", 3);

	ft_printf("ft: %%%%%%%%%% %d\n", 3);
	printf("ft: %%%%%%%%%% %d\n", 3);
}

void	color_tests(void)
{
	ft_printf("{RED}Hi{RESET}, i'm {CYAN}colored{RESET}, {UNDERLINE}underlined{RESET}, {MAGENTA}{UNDERLINE}colored and underlined{RESET}.\n");
	ft_printf("Color {%1$s}given{%3$s} in {%2$s}string{%3$s}.\n", "CYAN", "MAGENTA", "RESET");
	//ft_printf("{MAGENTA}Purple{RESET}%c{CYAN}cyan{RESET}\n", 0);
}

int	main(void)
{
	/*
	mixed_index_tests();
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
	ft_printf("\n");
	binary_tests();
	ft_printf("\n");
	percent_tests();
	*/
	/*
	ft_printf("Color {%1$s}given{%3$s} in {%2$s}string{%3$s}.\n", "CYAN", "MAGENTA", "RESET");
	ft_printf("Color {%1$s}given{%3$s} in {%2$s}string{%3$s}.\n", "CYAN", "MAGENTA", "RESET");
	*/
		ft_printf("WTF - {%s} works not {RESET} {CYAN}???{RESET}\n", "RED");
	while (1)
		ft_printf("{RED}RED{RESET}\n");
	return (0);
}