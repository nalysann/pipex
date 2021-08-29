/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:58:56 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/28 16:59:02 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "pipex.h"

static void	set_fd_in(int flags, t_pipex *pipex)
{
	int	fd_in;

	fd_in = STDIN_FILENO;
	if (flags & FD_FILE_IN)
	{
		fd_in = open(pipex->infile, O_RDONLY);
		if (fd_in < 0)
			ft_perror2(NAME, pipex->infile, E_OPEN_FAIL);
	}
	else if (flags & FD_PIPE_IN)
		fd_in = pipex->fd_pipe[0];
	if (dup2(fd_in, STDIN_FILENO) < 0)
		ft_perror(NAME, E_DUP2_FAIL);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (!(flags & FD_PIPE_IN))
		close(pipex->fd_pipe[0]);
}

static void	set_fd_out(int flags, t_pipex *pipex)
{
	int	fd_out;

	fd_out = STDOUT_FILENO;
	if (flags & FD_FILE_OUT)
	{
		fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out < 0)
			ft_perror2(NAME, pipex->outfile, E_OPEN_FAIL);
	}
	else if (flags & FD_PIPE_OUT)
		fd_out = pipex->fd_pipe[1];
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		ft_perror(NAME, E_DUP2_FAIL);
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
	if (!(flags & FD_PIPE_OUT))
		close(pipex->fd_pipe[1]);
}

static void	create_child_process(const char *cmd, int flags, t_pipex *pipex)
{
	char	**argv;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_perror(NAME, E_FORK_FAIL);
	if (pid == 0)
	{
		argv = ft_strsplit(cmd, ' ');
		if (argv[0] == NULL)
			ft_error2(NAME, EMPTY_CMD_MSG, E_EMPTY_CMD);
		set_fd_in(flags, pipex);
		set_fd_out(flags, pipex);
		ft_execlp(argv, pipex);
	}
	if (flags & ST_SAVE)
		pipex->last_pid = pid;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	pid_t	pid;
	int		status;

	if (argc != 5)
		ft_error2(NAME, INV_ARGC_MSG, E_INV_ARGC);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.envp = envp;
	pipex.path_dirs = get_path_dirs(envp);
	if (pipe(pipex.fd_pipe) < 0)
		ft_perror(NAME, E_PIPE_FAIL);
	create_child_process(argv[2], FD_FILE_IN | FD_PIPE_OUT, &pipex);
	create_child_process(argv[3], FD_PIPE_IN | FD_FILE_OUT | ST_SAVE, &pipex);
	close(pipex.fd_pipe[0]);
	close(pipex.fd_pipe[1]);
	pid = 1;
	while (pid > 0)
	{
		pid = wait(&status);
		if (pid == pipex.last_pid)
			pipex.last_status = status;
	}
	free_split(pipex.path_dirs);
	return (WEXITSTATUS(pipex.last_status));
}
