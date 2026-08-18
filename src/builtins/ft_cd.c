
#include "../minishell.h"
#include <libft.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FT_CD_ERR 1
#define FT_CD_SUCCESS 0

static int	update_pwd(t_shell *sh)
{
	char	*pwd;

	pwd = ft_getvar(sh->var, "PWD");
	if (pwd != NULL)
	{
		if (ft_setvar(sh->var, "OLDPWD", pwd) == -1)
			return (FT_CD_ERR);
	}
	else
		delete_var(&sh->var, "OLDPWD");
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("mish: cd");
		return (FT_CD_ERR);
	}
	if (ft_setvar(sh->var, "PWD", pwd) == -1)
	{
		free(pwd);
		return (FT_CD_ERR);
	}
	free(pwd);
	return (FT_CD_SUCCESS);
}

static void	pre_fix_path(char *path)
{
	char	*ptr;

	ptr = ft_strnstr(path, "/./", ULONG_MAX);
	if (ptr == NULL)
		ptr = ft_strnstr(path, "//", ULONG_MAX);
	while (ptr != NULL)
	{
		ft_memmove(ptr + 1, ptr + 2, ft_strlen(ptr + 2) + 1);
		ptr = ft_strnstr(path, "/./", ULONG_MAX);
		if (ptr == NULL)
			ptr = ft_strnstr(path, "//", ULONG_MAX);
	}
}

static void	fix_path(char *path)
{
	char	*ptr;
	char	*dest;

	pre_fix_path(path);
	ptr = ft_strnstr(path, "/..", ULONG_MAX);
	while (ptr != NULL)
	{
		dest = ptr;
		if (ptr != path)
			dest = ptr - 1;
		while (dest != path && *dest != '/')
			dest--;
		if (dest != path)
			ft_memmove(dest, ptr + 3, ft_strlen(ptr + 3) + 1);
		else
			ft_memmove(dest + 1, ptr + 3, ft_strlen(ptr + 3) + 1);
		ptr = ft_strnstr(path, "/..", ULONG_MAX);
	}
	ptr = ft_strnstr(path, "/.", ULONG_MAX);
	while (ptr != NULL)
	{
		ft_memmove(ptr, ptr + 2, ft_strlen(ptr + 2) + 1);
		ptr = ft_strnstr(path, "/.", ULONG_MAX);
	}
}

static char	*cd_get_path(int argc, char **argv, t_shell *sh)
{
	char	*path;
	char	*str[4];

	ft_bzero(str, (sizeof(char *)) * 4);
	if (argc == 1)
	{
		path = ft_getvar(sh->var, "HOME");
		if (path == NULL)
			ft_putstr_fd("mish: cd: HOME not set\n", STDERR_FILENO);
		if (path == NULL)
			return (NULL);
	}
	else if (argv[1][0] == '/')
		path = argv[1];
	else
	{
		str[0] = getcwd(NULL, 0);
		str[1] = "/";
		str[2] = argv[1];
		path = ft_strconcat(str);
		if (str[0] == NULL || path == NULL)
			return (free(str[0]), free(path), perror("malloc\n"), NULL);
		fix_path(path);
	}
	return (free(str[0]), path);
}

int	ft_cd(int argc, char **argv, t_shell *sh)
{
	int		ret;
	char	*path;

	if (argc > 2)
	{
		ft_putstr_fd("mish: cd: too many arguments\n", STDERR_FILENO);
		return (FT_CD_ERR);
	}
	path = cd_get_path(argc, argv, sh);
	if (path == NULL)
		return (FT_CD_ERR);
	ret = chdir(path);
	if (argc != 1 && argv[1][0] != '/')
		free(path);
	if (ret != 0)
	{
		ft_putstr_fd("mish: cd: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(NULL);
		return (FT_CD_ERR);
	}
	if (update_pwd(sh) == FT_CD_ERR)
		return (FT_CD_ERR);
	return (FT_CD_SUCCESS);
}

// int	main(void)
// {
// 	char *pwd = getcwd(NULL, 0);
// 	printf("%s\n", pwd);
// 	free(pwd);
// 	//
// 	int ret = chdir("../linux_sample/../../././cursus/../cursus/linux_sample");
// 	printf("%d\n", ret);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	//
// 	ret = chdir("./chdir_err.c");
// 	perror(NULL);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	//
// 	ret = chdir(".");
// 	printf("%d\n", ret);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	//
// 	ret = chdir("..");
// 	printf("%d\n", ret);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	//
// 	ret = chdir("~/cursus/linux_sample");
// 	printf("%d\n", ret);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	//
// 	ret = chdir("");
// 	printf("%d\n", ret);
// 	pwd = getcwd(NULL, 0);
// 	printf("getcwd %s\n", pwd);
// 	printf("getenv %s\n", getenv("PWD"));
// 	free(pwd);
// 	return (0);
// }