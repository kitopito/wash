
#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

// buitin
# define BUILTIN_NUM 7
# define CMD_ECHO "echo"
# define CMD_CD "cd"
# define CMD_PWD "pwd"
# define CMD_EXPORT "export"
# define CMD_UNSET "unset"
# define CMD_ENV "env"
# define CMD_EXIT "exit"

int	ft_exit(int argc, char **argv, t_shell *sh);

int	ft_cd(int argc, char **argv, t_shell *sh);

int	ft_pwd(int argc, char **argv, t_shell *sh);

int	ft_env(int argc, char **argv, t_shell *sh);

int	ft_unset(int argc, char **argv, t_shell *sh);

int	ft_export(int argc, char **argv, t_shell *sh);

int	ft_echo(int argc, char **argv, t_shell *sh);

int	ft_getopt(int argc, char **argv, char *optarg, const char *optsting);

int	is_valid_identifier(const char *str);

int	ft_setvar_builtin(int argc, char **argv, t_shell *sh);
int	ft_setvar_builtin_1(char *arg, t_var *var, t_shell *sh);

int	ft_dummy(int argc, char **argv, t_shell *sh);

#endif