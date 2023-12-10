#include "bash.h"

void	bash_init(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	memset(g_except, 0, sizeof(int) * EX_END);
	memset(g_flag, 0, sizeof(int) * F_END);
	g_envp = copy_2d_arr(envp, MAX);
	catch_signals();
}

void	exit_bash(char ***cmds)
{
	putstr_newline("exit");
	if (cmds)
	{
		if (cmds[0][1])
		{
			putstr("-bash: exit: ");
			putstr(cmds[0][1]);
			putstr_newline(": numeric argument required");
		}
		free_3d_arr(cmds);
	}
	free_2d_arr(g_envp);
	exit(0);
}

int		main(int argc, char **argv, char **envp)
{ 
	char	***cmds;
	char	*line;

	bash_init(argc, argv, envp);
	while (1)
	{
		if (g_flag[CTRL_BS])
			g_flag[CTRL_BS] = 0;
		else
			putstr("bash$ ");
		while (!(get_next_line(0, &line)))
		{
			if (!g_flag[CTRL_D] && !line[0])
				exit_bash(0);
			g_flag[CTRL_D] = 1;
		}
		memset(g_flag, 0, sizeof(int) * F_END);
		cmds = parsing_cmds(line);
		exec_cmds(cmds);
		free_3d_arr(cmds);
	}
	return (0);
}
