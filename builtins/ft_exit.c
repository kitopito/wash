
#include "../minishell.h"
#include <libft.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	check_valid_arg(int argc, char *exit_str, char *arg_str,
				t_shell *sh);
static int	ft_islong(const char *str);

static void	ft_exit1(int argc, t_shell *sh)
{
	char	status;

	if (argc == 1)
	{
		status = (char)ft_atoi(ft_getvar(sh->var, "?"));
		destroy_shell(sh);
		exit(status);
	}
}

int	ft_exit(int argc, char **argv, t_shell *sh)
{
	char	*exit_str;
	int		sign;
	char	status;

	printf("exit\n");
	ft_exit1(argc, sh);
	exit_str = argv[1];
	while (ft_isspace(*exit_str))
		exit_str++;
	sign = 1;
	if (exit_str[0] == '+' || exit_str[0] == '-')
		if (*(exit_str++) == '-')
			sign = -sign;
	if (check_valid_arg(argc, exit_str, argv[1], sh) == 1)
		return (1);
	status = 0;
	while (*exit_str != '\0' && ft_isdigit(*exit_str))
	{
		status = status * 10 + sign * (*exit_str - '0');
		exit_str++;
	}
	destroy_shell(sh);
	exit(status);
}

static int	check_valid_arg(int argc, char *exit_str, char *arg_str,
		t_shell *sh)
{
	while (*exit_str != '\0' && ft_isspace(*exit_str) == 0)
	{
		if (ft_isdigit(*exit_str) == 0)
			break ;
		exit_str++;
	}
	while (ft_isspace(*exit_str))
		exit_str++;
	if (*exit_str != '\0' || ft_islong(arg_str) == 0)
	{
		ft_putstr_fd("mish: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg_str, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		destroy_shell(sh);
		exit(2);
	}
	if (argc > 2)
	{
		ft_putstr_fd("mish: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

static int	check_overflow(long num, char c, int sign)
{
	int	digit;

	digit = sign * (c - '0');
	if (sign > 0)
	{
		if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && digit > LONG_MAX
				% 10))
			return (0);
		else
			return (1);
	}
	else
	{
		if (num < LONG_MIN / 10 || (num == LONG_MIN / 10 && digit < LONG_MIN
				% 10))
			return (0);
		else
			return (1);
	}
}

static int	ft_islong(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		if (check_overflow(result, str[i], sign))
			result = result * 10 + sign * (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	int r;
// 	r = ft_islong("0");
// 	printf("%d\n", r);
// 	r = ft_islong("+12345678");
// 	printf("%d\n", r);
// 	r = ft_islong("+12345678901234567890");
// 	printf("%d\n", r);
// 	r = ft_islong("-12345678901234567890");
// 	printf("%d\n", r);
// 	r = ft_islong("  9223372036854775807  ");
// 	printf("%d\n", r);
// 	r = ft_islong("  +9223372036854775807  ");
// 	printf("%d\n", r);
// 	r = ft_islong("  -9223372036854775808  ");
// 	printf("%d\n", r);
// 	r = ft_islong("  9223372036854775808  ");
// 	printf("%d\n", r);
// 	r = ft_islong("  +9223372036854775808  ");
// 	printf("%d\n", r);
// 	r = ft_islong("  -9223372036854775809  ");
// 	printf("%d\n", r);
// 	r = ft_islong("abc");
// 	printf("%d\n", r);
// 	r = ft_islong(" abc");
// 	printf("%d\n", r);
// 	r = ft_islong(" 1abc");
// 	printf("%d\n", r);
// }