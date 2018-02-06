#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	int		i;
	wchar_t *str = L"сторін ...";

	if (argc != 3)
		return (1);
	setlocale(LC_ALL, "");
	i = 0;
	while (str[i])
	{
		printf("%lc\n", str[i++]);
	}
	return (0);
}
