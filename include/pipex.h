#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>

#define NAME "pipex"

#define INV_ARGC_MSG "invalid argument count"
#define EMPTY_CMD_MSG "empty command"
#define PATH_PERM_MSG "permission denied"
#define PATH_NOCMD_MSG "command not found"

#define E_INV_ARGC 1
#define E_EMPTY_CMD 2
#define E_DUP2_FAIL 3
#define E_PIPE_FAIL 4
#define E_FORK_FAIL 5
#define E_OPEN_FAIL 6
#define E_EXEC_FAIL 7
#define E_PATH_PERM 8
#define E_PATH_NOCMD 9

#define FD_STDIN 1
#define FD_FILE_IN 2
#define FD_PIPE_IN 4
#define FD_STDOUT 8
#define FD_FILE_OUT 16
#define FD_PIPE_OUT 32

struct s_pipex
{
	int		fd_pipe[2];
	char	*infile;
	char	*outfile;
	char	**envp;
	char	**path_dirs;
};

typedef struct s_pipex t_pipex;

#endif
