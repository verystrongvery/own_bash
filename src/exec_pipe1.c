#include "bash.h"

char	***pipe_split(char **cmd)
{
	char	***cmds;
	int		pipe_i[MAX];
	int		pipe_n;
	int		i;

	pipe_n = 0;
	i = -1;
	pipe_i[0] = 0;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			pipe_i[++pipe_n] = i;
	if (!pipe_n)
		return (NULL);
	pipe_i[++pipe_n] = i;
	cmds = (char ***)malloc(sizeof(char *) * (pipe_n + 1));
	cmds[0] = copy_2d_arr(cmd, pipe_i[1] - pipe_i[0]);
	i = 0;
	while (++i < pipe_n)
		cmds[i] = copy_2d_arr(&cmd[pipe_i[i] + 1],
			pipe_i[i + 1] - pipe_i[i] - 1);
	cmds[i] = NULL;
	return (cmds);
}

char	**allocate_path(char ***cmds)
{
	char	**path;
	int		n;
	int		i;

	n = 0;
	while (cmds[n])
		n++;
	path = (char **)malloc(sizeof(char *) * (n + 1));
	i = -1;
	while (++i < n)
	{
		if (!(path[i] = find_path(cmds[i][0])))
		{
			putstr(cmds[i][0]);
			putstr_newline(": command not found");
			free_2d_arr(path);
			return (NULL);
		}
	}
	path[i] = NULL;
	return (path);
}

int		pipes(char **cmd)
{
	char	***cmds;
	char	**path;
	pid_t	pid;
	int		fd[2];
	int		status;

	if (!(cmds = pipe_split(cmd)))
		return (0);
	path = allocate_path(cmds);
	if (path)
	{
		pid = fork();
		if (!pid)
		{
			pipe(fd);
			pipes_exec(cmds, path, fd, 0);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		g_exit_code = status / 256;
	}
	free_3d_arr(cmds);
	free_2d_arr(path);
	return (1);
}
