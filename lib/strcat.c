#include "lib.h"

char	*strcat(char *s1, const char *s2)
{
	int i;
	int	s1_len;

	i = -1;
	s1_len = _strlen(s1);
	while (s2[++i])
		s1[s1_len + i] = s2[i];
	s1[s1_len + i] = '\0';
	return (s1);
}
