#ifndef LIBH
# define LIBH

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NOTHING	-1
# define AUTO_SIZE	0
# define FILE_SIZE	1024
# define MAX		1000

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	putstr(const char *s);
void	putstr_newline(const char *s);
void	putnbr(int n);
void	free_2d_arr(char **arr);
void	free_3d_arr(char ***arr);
void	free_init(char **data, char *init);

void	*memset(void *ptr, int value, size_t num);
void	print_2d_arr(char **arr);
void	print_newline_2d_arr(char **arr);

char	*gnljoin(char *buff, char *temp);
char	*_strdup(const char *s);
char	*substr(char const *s, unsigned int start, size_t len);
char	*strcat(char *s1, const char *s2);
char	*itoa(int n);
char	*strjoin(char const *s1, char const *s2);
char	*_strndup(char *str, int size);

char	**split(char const *s, char c);
char	**split_one(char *str, char c);
char	**copy_2d_arr(char **arr, int size);

int		_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		strncmp(const char *str1, const char *str2, size_t num);
int		_strchr(char *str, char c);
int		strcmp(const char *s1, const char *s2);

#endif
