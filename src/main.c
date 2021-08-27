/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:21:01 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/26 12:53:13 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "pipex.h"

static char	*get_cmd_path(const char *path, const char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	tmp = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (cmd_path);
}
static void	ft_execlp(char **argv, t_pipex *pipex)
{
	char	*cmd_path;
	int		exists;
	int		i;

	i = 0;
	exists = 0;
	while (pipex->path_dirs[i])
	{
		cmd_path = get_cmd_path(pipex->path_dirs[i], argv[0]);
		if (!access(cmd_path, F_OK))
			exists = 1;
		if (!access(cmd_path, X_OK))
			break;
		free(cmd_path);
		++i;
	}
	if (exists && pipex->path_dirs[i])
	{
		execve(cmd_path, argv, pipex->envp);
		ft_perror(NAME, E_EXEC_FAIL);
	}
	else if (exists)
		ft_error3(NAME, PATH_PERM_MSG, argv[0], E_PATH_PERM);
	else
		ft_error3(NAME, PATH_NOCMD_MSG, argv[0], E_PATH_NOCMD);
}

static void	set_descriptors(int fd_flags, t_pipex *pipex)
{
	int	fd_in;
	int	fd_out;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	if (fd_flags & FD_FILE_IN)
		fd_in = open(pipex->infile, O_RDONLY);
	if (fd_flags & FD_PIPE_IN)
		fd_in = pipex->fd_pipe[0];
	if (fd_in < 0)
		ft_error3(NAME, strerror(errno), pipex->infile, E_OPEN_FAIL);
	if (dup2(fd_in, STDIN_FILENO) < 0)
		ft_perror(NAME, E_DUP2_FAIL);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (fd_flags & FD_FILE_OUT)
		fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_flags & FD_PIPE_OUT)
		fd_out = pipex->fd_pipe[1];
	if (fd_out < 0)
		ft_error3(NAME, strerror(errno), pipex->outfile, E_OPEN_FAIL);
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		ft_perror(NAME, E_DUP2_FAIL);
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
}

static void	create_child_process(const char* cmd, int fd_flags, t_pipex *pipex)
{
	char	**argv;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_perror(NAME, E_FORK_FAIL);
	if (pid == 0)
	{
		argv = ft_strsplit(cmd, ' ');
		if (argv == NULL)
			ft_error2(NAME, EMPTY_CMD_MSG, E_EMPTY_CMD);
		set_descriptors(fd_flags, pipex);
		ft_execlp(argv, pipex);
//		free_split(argv);
	}
}

static char	**get_path_dirs(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strstartswith(envp[i], "PATH=")) {
			path = envp[i] + 5;
			break;
		}
		++i;
	}
	return (ft_strsplit(path, ':'));
}

int		main(int argc, char* argv[], char* envp[]) {
	t_pipex	pipex;

	if (argc != 5)
		ft_error2(NAME, INV_ARGC_MSG, E_INV_ARGC);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.envp = envp;
	pipex.path_dirs = get_path_dirs(envp);
	if (pipe(pipex.fd_pipe) < 0)
		ft_perror(NAME, E_PIPE_FAIL);
	create_child_process(argv[2], FD_FILE_IN | FD_PIPE_OUT, &pipex);
	create_child_process(argv[3], FD_PIPE_IN | FD_FILE_OUT, &pipex);
	close(pipex.fd_pipe[0]);
	close(pipex.fd_pipe[1]);
	wait(NULL);
	wait(NULL);
	free_split(pipex.path_dirs);
}
