#include "lib.h"

void	putstr(const char *s)
{
	write(1, s, _strlen(s));
}

void	putstr_newline(const char *s)
{
	putstr(s);
	write(1, "\n", 1);
}
