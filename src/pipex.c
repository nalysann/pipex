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

#include <sys/wait.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"

#include "pipex.h"

static void	run_pipeline(char *argv[], t_pipex *pipex)
{
	if (pipe(pipex->fd_pipe) < 0)
		ft_perror(NAME, E_PIPE_FAIL);
	create_child_process(argv[2], FD_FILE_IN | FD_PIPE_OUT, pipex);
	create_child_process(argv[3], FD_PIPE_IN | FD_FILE_OUT | ST_SAVE, pipex);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
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
	pipex.heredoc = 0;
	pipex.prev_fd_in = -1;
	run_pipeline(argv, &pipex);
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
