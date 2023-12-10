#include "lib.h"

int		sign_check(int *n)
{
	if (*n >= 0)
		return (1);
	*n *= -1;
	return (-1);
}

void	putnbr(int n)
{
	int		sign;

	sign = sign_check(&n);
	if (sign == -1)
		write(1, "-", 1);
	if (n >= 10)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}
