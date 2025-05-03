
#ifndef EXE_CMD_H
# define EXE_CMD_H

# include "../minishell.h"

int		exe_cmd_solo(t_shell *sh, t_cmd *cmd, int pipe_in, int pipe_out);

int		is_builin(const char *cmd);

int		exe_builtin(t_cmd *cmd, t_shell *sh);

char	*search_cmd_path(char *cmd, t_shell *sh);

int		exe_cmd_solo(t_shell *sh, t_cmd *cmd, int pipe_in, int pipe_out);

int		exe_cmd(t_cmd *cmd, t_shell *sh);

int		is_directory(const char *path);

int		process_heredoc(t_cmd *cmd, t_shell *sh);

char	*parse_heredoc(char *line, t_var *var);

#endif