CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = format_specifier.c ft_print_util.c ft_print_string.c \
		ft_print_pointer.c ft_print_integer.c ft_vprintf.c ft_printf.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS) 

$(LIBFT):
	cd "$(shell pwd)/libft" && make bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)
	cd "$(shell pwd)/libft" && make clean

fclean: clean
	rm -f $(NAME)
	cd "$(shell pwd)/libft" && make fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
