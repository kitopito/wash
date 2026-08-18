
#include "../builtins/builtins.h"
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	is_builin(const char *cmd)
{
	char	*eq_ptr;

	if (ft_strcmp(cmd, CMD_ECHO) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_CD) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_PWD) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_EXPORT) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_UNSET) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_ENV) == 0)
		return (1);
	if (ft_strcmp(cmd, CMD_EXIT) == 0)
		return (1);
	if (ft_strcmp(cmd, "ft_dummy") == 0)
		return (1);
	eq_ptr = ft_strchr(cmd, '=');
	if (eq_ptr != NULL && eq_ptr != cmd)
		return (1);
	return (0);
}

int	exe_builtin(t_cmd *cmd, t_shell *sh)
{
	int	status;

	status = 127;
	if (ft_strcmp(cmd->cmd, "exit") == 0)
		status = ft_exit(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		status = ft_cd(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		status = ft_pwd(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		status = ft_env(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		status = ft_unset(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		status = ft_export(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		status = ft_echo(cmd->argc, cmd->args, sh);
	else if (ft_strcmp(cmd->cmd, "ft_dummy") == 0)
		status = ft_dummy(cmd->argc, cmd->args, sh);
	else if (ft_strchr(cmd->cmd, '=') != NULL)
		status = ft_setvar_builtin(cmd->argc, cmd->args, sh);
	return (status);
}

static char	*search_cmd_path_list(char *cmd, t_shell *sh)
{
	char	*path_tmp[4];
	char	**path_list;
	char	*path;
	size_t	i;

	path = NULL;
	path_list = get_path_list(sh);
	if (path_list == NULL)
		return (NULL);
	i = 0;
	while (path_list[i] != NULL)
	{
		path_tmp[0] = path_list[i++];
		path_tmp[1] = "/";
		path_tmp[2] = cmd;
		path_tmp[3] = NULL;
		path = ft_strconcat(path_tmp);
		if (path == NULL)
			return (ft_free_strs(path_list), NULL);
		if (access(path, X_OK) == 0)
			return (ft_free_strs(path_list), path);
		free(path);
	}
	ft_free_strs(path_list);
	return (NULL);
}

char	*search_cmd_path(char *cmd, t_shell *sh)
{
	char	*path;
	char	*path_tmp[4];

	path_tmp[1] = "/";
	path_tmp[2] = cmd;
	path_tmp[3] = NULL;
	path = search_cmd_path_list(cmd, sh);
	if (path != NULL)
		return (path);
	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	else if (cmd[0] == '/')
		return (NULL);
	if (ft_strchr(cmd, '/') == NULL && cmd[0] != '.')
		return (NULL);
	path_tmp[0] = getcwd(NULL, 0);
	if (path_tmp[0] == NULL)
		return (perror("getcwd"), NULL);
	path = ft_strconcat(path_tmp);
	if (path == NULL)
		return (free(path_tmp[0]), NULL);
	if (access(path, F_OK) == 0)
		return (free(path_tmp[0]), path);
	free(path);
	return (free(path_tmp[0]), NULL);
}
