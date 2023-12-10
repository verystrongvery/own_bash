#include "bash.h"

void	do_except(char **cmds)
{
	if (g_except[SYNTAX])
	{
		putstr("-bash: syntax error near unexpected token `");
		if (g_except[SYNTAX] == '|')
			putstr_newline("|'");
		else if (_strchr("<>", g_except[SYNTAX]) != NOTHING)
			putstr_newline("newline'");
	}
	else
	{
		putstr("bash: ");
		putstr(*cmds);
		putstr_newline(": command not found");
	}
	exit(127);
}

void	exec_cmds(char ***cmds)
{
	int i;

	if (!cmds)
		return ;
	i = -1;
	while (cmds[++i])
	{
		if (g_except[NONE])
			g_except[NONE] = 0;
		else if (pipes(cmds[i]) ||
			redirections(cmds[i]) ||
			builtins(cmds[i], cmds) ||
			excutables(1, 0, cmds[i]))
		{
		}
		else
			do_except(cmds[i]);
	}
}
