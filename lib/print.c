#include "lib.h"

void	print_2d_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		putstr(arr[i]);
		if (arr[i + 1])
			write(1, " ", 1);
	}
}

void	print_newline_2d_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		putstr_newline(arr[i]);
}
