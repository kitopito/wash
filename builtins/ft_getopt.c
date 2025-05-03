
#include <libft.h>
#include <stddef.h>
#include <stdio.h>

static int	read_opt(char *arg_str, char *optarg, const char *optsting)
{
	size_t	j;
	size_t	k;

	j = 1;
	while (arg_str[j] != '\0')
	{
		if (ft_strchr(optsting, arg_str[j++]) == NULL)
			return (-1);
	}
	j = 1;
	while (arg_str[j] != '\0')
	{
		if (ft_strchr(optarg, arg_str[j]) == NULL)
		{
			k = 0;
			while (optarg[k] != '\0')
				k++;
			optarg[k] = arg_str[j];
		}
		j++;
	}
	return (0);
}

// returns the first non-option argument index
int	ft_getopt(int argc, char **argv, char *optarg, const char *optsting)
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			if (read_opt(argv[i], optarg, optsting) == -1)
				return (i);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char		optarg[256];
// 	char		*opt1;
// 	char		*argv1[] = {"./minishell", "-n", "Hello", "World"};
// 	int			argc1;
// 	int			ret1;
// 	char		*argv2[] = {"./minishell", "-nnnn", "-nn", "World"};
// 	const char	*opt2 = "n";
// 	const int	argc2 = 4;
// 	int			ret2;
// 	char		*argv3[] = {"./minishell", "-", "-nn", "World"};
// 	const char	*opt3 = "n";
// 	const int	argc3 = 4;
// 	int			ret3;
// 	char		*argv4[] = {"./minishell", " -n", "-nn", "World"};
// 	const char	*opt4 = "n";
// 	const int	argc4 = 4;
// 	int			ret4;
// 	char		*argv5[] = {"./minishell", "-n ", "-nn", "World"};
// 	const char	*opt5 = "n";
// 	const int	argc5 = 4;
// 	int			ret5;
// 	char		*argv6[] = {"./minishell", "-nhknhk", "-nn", "World"};
// 	const char	*opt6 = "nhk";
// 	const int	argc6 = 4;
// 	int			ret6;

// 	ft_bzero(optarg, sizeof(optarg));
// 	opt1 = "n";
// 	argc1 = 4;
// 	ret1 = ft_getopt(argc1, argv1, optarg, opt1);
// 	printf("%d\n", ret1);
// 	//
// 	ft_bzero(optarg, sizeof(optarg));
// 	ret2 = ft_getopt(argc2, argv2, optarg, opt2);
// 	printf("%d\n", ret2);
// 	//
// 	ft_bzero(optarg, sizeof(optarg));
// 	ret3 = ft_getopt(argc3, argv3, optarg, opt3);
// 	printf("%d\n", ret3);
// 	//
// 	ft_bzero(optarg, sizeof(optarg));
// 	ret4 = ft_getopt(argc4, argv4, optarg, opt4);
// 	printf("%d\n", ret4);
// 	//
// 	ft_bzero(optarg, sizeof(optarg));
// 	ret5 = ft_getopt(argc5, argv5, optarg, opt5);
// 	printf("%d\n", ret5);
// 	//
// 	ft_bzero(optarg, sizeof(optarg));
// 	ret6 = ft_getopt(argc6, argv6, optarg, opt6);
// 	printf("%d\n", ret6);
// 	return (0);
// }

// gcc libft/ft_strchr.c libft/ft_bzero.c builtins/ft_getopt.c -Ilibft