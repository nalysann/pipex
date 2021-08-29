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

static char	*get_cmd_path(const char *path, const char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	tmp = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (cmd_path);
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
		cmd_path = get_cmd_path(pipex->path_dirs[i], argv[0]);
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
