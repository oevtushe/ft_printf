NAME := ft_printf
SRCS := main.c
OBJS := $(SRCS: %.c=%.o)

KEYS := -Wall -Werror -Wextra -g

LIB := libft.a

all: $(NAME)

$(NAME): $(OBJS) libft/$(LIB)
	gcc $(KEYS) -o $@ $^ -I./libft/includes -L./libft -lft

%.o: %.c
	gcc $(KEYS) -c $< -I./libft/includes -L./libft -lft

$(LIB):
	$(MAKE) -C libft/
