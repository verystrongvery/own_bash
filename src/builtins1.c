#include "bash.h"

char	*find_home(void)
{
	char	*home;
	int		i;

	home = NULL;
	i = -1;
	while (g_envp[++i])
	{
		if (!strncmp(g_envp[i], "HOME=", 5))
		{
			home = _strdup(g_envp[i] + 5);
			break ;
		}
	}
	return (home);
}

void	do_cd(char **argv)
{
	char	*err_msg;
	char	*home;
	int		i;

	if (argv[2])
	{
		i = 1;
		while (argv[++i])
			free(argv[i]);
		argv[2] = NULL;
	}
	if (!argv[1])
	{
		home = find_home();
		chdir(home);
		free(home);
	}
	else if (chdir(argv[1]) == -1)
	{
		err_msg = strerror(errno);
		putstr("-bash: cd: ");
		putstr(argv[1]);
		putstr(": ");
		putstr_newline(err_msg);
	}
}

void	do_env(char **argv)
{
	int i;

	i = -1;
	if (argv[1])
	{
		putstr("env: ");
		putstr(argv[1]);
		putstr_newline(": No such file or directory");
		return ;
	}
	while (g_envp[++i] && g_envp[i][0])
		putstr_newline(g_envp[i]);
}

int		builtins(char **argv, char ***cmds)
{
	if (!argv[0])
		return (0);
	if (!strcmp(argv[0], "echo") || (!strcmp(argv[0], "pwd")))
		excutables(1, 0, argv);
	else if (!strcmp(argv[0], "cd"))
		do_cd(argv);
	else if (!strcmp(argv[0], "exit"))
		exit_bash(cmds);
	else if (!strcmp(argv[0], "env"))
		do_env(argv);
	else if (!strcmp(argv[0], "export"))
		do_export(argv);
	else if (!strcmp(argv[0], "unset"))
		do_unset(argv);
	else
		return (0);
	return (1);
}
