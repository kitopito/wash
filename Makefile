CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = wash

VAR_DIR = variable/
VAR_SRCS = variable.c var_util.c init_var.c 
BUILTIN_DIR = builtins/
BUILTIN_SRCS = ft_exit.c ft_cd.c ft_pwd.c ft_env.c  ft_export2.c ft_dummy.c \
	ft_unset.c ft_export.c ft_echo.c ft_getopt.c ft_setvar_builtin.c
EXE_CMD_DIR = exe_cmd/
EXE_CMD_SRCS = exe_cmd.c exe_cmd_util.c heredoc.c exe_cmd_solo.c heredoc_expand.c
SIGNAL_DIR = signal/
SIGNAL_SRCS = shell_signal.c set_shell_signal.c
PARSE_DIR = parse/
PARSE_SRCS = parse.c 

SRCS = main.c util.c get_path_list.c   minishell.c \
	$(addprefix $(VAR_DIR), $(VAR_SRCS)) \
	$(addprefix $(BUILTIN_DIR), $(BUILTIN_SRCS)) \
	$(addprefix $(EXE_CMD_DIR), $(EXE_CMD_SRCS)) \
	$(addprefix $(SIGNAL_DIR), $(SIGNAL_SRCS)) \
	$(addprefix $(PARSE_DIR), $(PARSE_SRCS))
#OBJ_DIR = obj/
OBJS := $(SRCS:.c=.o)
LIBFT = libft/libft.a 

LIBS = -lreadline
INCLUDES = -Ilibft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) -v $(CFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) 

$(LIBFT):
	make -C libft bonus

#$(OBJ_DIR):
#	mkdir $(OBJ_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(B_OBJS)
#	rm -r $(OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

bonus: all

debug: 
	make re DEBUG=-g

.PHONY: all clean fclean re bonus debug
