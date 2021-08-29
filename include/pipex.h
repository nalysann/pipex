/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:00:22 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/28 17:00:25 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

# define NAME "pipex"

# define INV_ARGC_MSG "invalid argument count"
# define EMPTY_CMD_MSG "empty command"
# define PATH_PERM_MSG "Permission denied"
# define PATH_NOCMD_MSG "command not found"

# define E_INV_ARGC 1
# define E_EMPTY_CMD 2
# define E_DUP_FAIL 3
# define E_DUP2_FAIL 4
# define E_PIPE_FAIL 5
# define E_FORK_FAIL 6
# define E_OPEN_FAIL 7
# define E_EXEC_FAIL 8
# define E_PATH_PERM 9
# define E_PATH_NOCMD 10

# define FD_FILE_IN 1
# define FD_PIPE_IN 2
# define FD_PREV_IN 4
# define FD_FILE_OUT 8
# define FD_PIPE_OUT 16
# define ST_SAVE 32

# define HEREDOC_MSG "pipe heredoc> "

struct s_pipex
{
	int		fd_pipe[2];
	char	*infile;
	char	*outfile;
	char	**envp;
	char	**path_dirs;
	pid_t	last_pid;
	int		last_status;
	int		heredoc;
	int		prev_fd_in;
};

typedef struct s_pipex	t_pipex;

char	**get_path_dirs(char **envp);
void	ft_execlp(char **argv, t_pipex *pipex);
void	create_child_process(const char *cmd, int flags, t_pipex *pipex);

#endif
