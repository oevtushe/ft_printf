NAME := ft_printf
SRCS := main.c \
		init_defaults.c \
		format_parser.c \
		ft_strappend.c \
		split_str.c \
		freshers.c \
		string_manager.c \
		init_assocs.c \
		spc_string.c
OBJS := $(SRCS:%.c=%.o)
DEPS := ft_printf.h

KEYS := -Wall -Werror -Wextra -g

LIB := libft/libft.a

all: $(NAME) $(LIB)

$(NAME): $(OBJS)
	gcc $(KEYS) -o $@ $^ -I./libft/includes -L./libft -lft

%.o: %.c $(DEPS)
	gcc $(KEYS) -c $< -I./libft/includes -L./libft -lft

$(LIB):
	$(MAKE) -C libft/

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean
	make

