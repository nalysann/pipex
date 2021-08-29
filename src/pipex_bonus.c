/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:59:10 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/28 16:59:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "pipex.h"

static void	feed_input(const char *limiter, t_pipex *pipex)
{
	char	*line;

	ft_putstr(HEREDOC_MSG);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strequ(line, limiter))
			break ;
		ft_putendl_fd(line, pipex->fd_pipe[1]);
		free(line);
		ft_putstr(HEREDOC_MSG);
	}
	free(line);
}

static void	heredoc(const char *limiter, t_pipex *pipex)
{
	pid_t	pid;

	pipex->heredoc = 1;
	if (pipe(pipex->fd_pipe) < 0)
		ft_perror(NAME, E_PIPE_FAIL);
	pid = fork();
	if (pid < 0)
		ft_perror(NAME, E_FORK_FAIL);
	if (pid == 0)
	{
		close(pipex->fd_pipe[0]);
		feed_input(limiter, pipex);
		exit(EXIT_SUCCESS);
	}
	else
	{
		pipex->prev_fd_in = dup(pipex->fd_pipe[0]);
		if (pipex->prev_fd_in < 0)
			ft_perror(NAME, E_DUP_FAIL);
		close(pipex->fd_pipe[0]);
		close(pipex->fd_pipe[1]);
		wait(NULL);
	}
}

static void	run_piped_process(const char *cmd, int in_flag, t_pipex *pipex)
{
	if (pipe(pipex->fd_pipe) < 0)
		ft_perror(NAME, E_PIPE_FAIL);
	create_child_process(cmd, in_flag | FD_PIPE_OUT, pipex);
	pipex->prev_fd_in = dup(pipex->fd_pipe[0]);
	if (pipex->prev_fd_in < 0)
		ft_perror(NAME, E_DUP_FAIL);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
}

static void	run_pipeline(int argc, char *argv[], t_pipex *pipex)
{
	int	i;

	if (argc > 5 && ft_strequ(argv[1], "here_doc"))
		heredoc(argv[2], pipex);
	else
		run_piped_process(argv[2], FD_FILE_IN, pipex);
	i = 3;
	while (i < argc - 2)
	{
		run_piped_process(argv[i], FD_PREV_IN, pipex);
		++i;
	}
	create_child_process(
		argv[argc - 2],
		FD_PREV_IN | FD_FILE_OUT | ST_SAVE,
		pipex);
	close(pipex->prev_fd_in);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	pid_t	pid;
	int		status;

	if (argc < 5)
		ft_error2(NAME, INV_ARGC_MSG, E_INV_ARGC);
	pipex.infile = argv[1];
	pipex.outfile = argv[argc - 1];
	pipex.envp = envp;
	pipex.path_dirs = get_path_dirs(envp);
	pipex.heredoc = 0;
	pipex.prev_fd_in = -1;
	run_pipeline(argc, argv, &pipex);
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
