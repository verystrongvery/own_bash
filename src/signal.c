#include "bash.h"

void	catch_sigint(int pid)
{
	(void)pid;
	putstr("\nbash$ ");
	g_flag[CTRL_BS] = 1;
}

void	catch_sigquit(int pid)
{
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (!pid)
		putstr("Quit: 3\n");
}

void	catch_signals(void)
{
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}
