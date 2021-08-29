/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:59:18 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/28 17:00:17 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_string.h"

#include "pipex.h"

char	**get_path_dirs(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strstartswith(envp[i], "PATH="))
		{
			path = envp[i] + 5;
			break ;
		}
		++i;
	}
	return (ft_strsplit(path, ':'));
}

void	ft_execlp(char **argv, t_pipex *pipex)
{
	char	*cmd_path;
	int		exists;
	int		i;

	i = 0;
	exists = 0;
	while (pipex->path_dirs[i])
	{
		cmd_path = ft_strjoin_sep(pipex->path_dirs[i], argv[0], "/");
		if (!access(cmd_path, F_OK))
			exists = 1;
		if (!access(cmd_path, X_OK))
			break ;
		free(cmd_path);
		++i;
	}
	if (exists && pipex->path_dirs[i])
	{
		execve(cmd_path, argv, pipex->envp);
		ft_perror(NAME, E_EXEC_FAIL);
	}
	else if (exists)
		ft_error3(NAME, argv[0], PATH_PERM_MSG, E_PATH_PERM);
	else
		ft_error3(NAME, argv[0], PATH_NOCMD_MSG, E_PATH_NOCMD);
}

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
	else if (flags & FD_PREV_IN)
		fd_in = pipex->prev_fd_in;
	if (dup2(fd_in, STDIN_FILENO) < 0)
		ft_perror(NAME, E_DUP2_FAIL);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (!(flags & FD_PIPE_IN))
		close(pipex->fd_pipe[0]);
	if (!(flags & FD_PREV_IN) && pipex->prev_fd_in > 0)
		close(pipex->prev_fd_in);
}

static void	set_fd_out(int flags, t_pipex *pipex)
{
	int	fd_out;

	fd_out = STDOUT_FILENO;
	if (flags & FD_FILE_OUT)
	{
		if (!pipex->heredoc)
			fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
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

void	create_child_process(const char *cmd, int flags, t_pipex *pipex)
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
