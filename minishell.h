
#ifndef MINISHELL_H
# define MINISHELL_H

# include "variable/variable.h"
# include <unistd.h>
# include <sys/types.h>

typedef struct s_command
{
	char				*cmd;
	int					argc;
	char				**args;
	int					input_fd;
	int					output_fd;
	int					append;
	char				*heredoc_delim;
	int					heredoc_pipe[2];
	char				*heredoc_buf;
	pid_t				pid;
	int					status;
	struct s_command	*next;
}						t_cmd;

typedef struct s_shell
{
	t_var				*var;
	int					exit_status;
	int					is_interactive;
	char				*line;
	t_cmd				*current_cmd;
}						t_shell;

void					destroy_shell(t_shell *sh);

char					**get_path_list(t_shell *sh);

void					print_error(char **message);
t_shell					*init_shell(void);
t_cmd					*new_cmd(void);
void					ft_free_cmd(t_cmd *cmd);

int						handle_redirections_output(t_var *var, t_cmd *cmd,
							char **args, int *i);
int						handle_redirections(t_var *var, t_cmd *cmd,
							char **args);

void					print_error_format(int mish, char *arg, char *msg);

#endif
