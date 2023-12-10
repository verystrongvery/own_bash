#include "lib.h"

char	*gnljoin(char *buff, char *temp)
{
	char	*data;
	int		i;
	int		j;

	if (!buff)
		return (NULL);
	if (!temp)
		return (buff);
	data = (char *)malloc(BUFFER_SIZE + _strlen(buff) + _strlen(temp) + 1);
	i = -1;
	while (buff[++i])
		data[i] = buff[i];
	j = -1;
	while (temp[++j])
		data[i + j] = temp[j];
	data[i + j] = '\0';
	free(buff);
	buff = NULL;
	return (data);
}
