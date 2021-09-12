# Pipex

This project is the discovery in detail and by programming of a UNIX
mechanism that you already know.

Objective is to code the Pipex program. It should be executed in this way:

``./pipex file1 cmd1 cmd2 file2``

Just in case: ``file1`` and ``file2`` are file names, ``cmd1`` and ``cmd2``
are shell commands with their parameters.

The execution of the pipex program should do the same as the next shell command:

``< file1 cmd1 | cmd2 > file2``

### Examples

- ``./pipex infile "ls -l" "wc -l" outfile`` should be the same as ``< infile ls -l | wc -l > outfile``
- ``./pipex infile "grep a1" "wc -w" outfile`` should be the same as ``< infile grep a1 | wc -w > outfile``

### Bonus:

- Handle multiple pipes:

    ``./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`` must be equivalent to ``< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2``

- Support ``<<`` and ``>>`` when the first parameter is ``here_doc``:
    
    ``./pipex here_doc LIMITER cmd cmd1 file`` must be equivalent to ``cmd << LIMITER | cmd1 >> file``

## HOWTO

Build with ``make`` for the basic part, or ``make bonus`` for the bonus part,
then follow the description above.
