#include "lib.h"

int		strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || (!*s1 && !*s2))
		return (*s1 - *s2);
	return (strcmp(s1 + 1, s2 + 1));
}
