NAME := ft_printf
SRCS := main.c init_defaults.c format_parser.c ft_strappend.c split_str.c
OBJS := $(SRCS: %.c=%.o)
DEPS := ft_printf.h

KEYS := -Wall -Werror -Wextra -g

LIB := libft.a

all: $(NAME) $(DEPS)

$(NAME): $(OBJS) libft/$(LIB)
	gcc $(KEYS) -o $@ $^ -I./libft/includes -L./libft -lft

%.o: %.c
	gcc $(KEYS) -c $< -I./libft/includes -L./libft -lft

$(LIB):
	$(MAKE) -C libft/
