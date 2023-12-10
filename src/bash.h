#ifndef BASH_H
# define BASH_H

# include "../lib/lib.h"
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

enum	e_quotes
{
	Q_E = -3,
	Q_B,
	Q_S,
	OUT,
	DQ_S,
	DQ_B,
	DQ_E
};

enum	e_except
{
	NONE,
	SYNTAX,
	EX_END
};

enum	e_flag
{
	CTRL_D,
	CTRL_BS,
	F_END
};

char **g_envp;
int g_exit_code;
int g_except[EX_END];
int	g_flag[F_END];

void	exit_bash(char ***cmds);
void	check_quotes(char *str, int quotes[], int *i);
void	split_one_more(char *str, int cmd_num, int idxs[][2], char ***ret);
void	exec_cmds(char ***cmds);
void	do_unset(char **argv);
void	do_export(char **argv);
void	catch_signals();
void	pipes_exec(char	***cmds, char **path, int *fd, int i);

int		redirections(char **cmd);
int		excutables(int fd_o, int fd_i, char **argv);
int		pipes(char **cmd);
int		builtins(char **argv, char ***cmds);

char	*find_path(char *cmd);

char	***parsing_cmds(char *str);
char	***split_cmds(char *str, int quotes[]);

#endif
