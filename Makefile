NAME := libftprintf.a

TD := tools/
TF := ft_strlen.c \
	   ft_strnew.c \
	   ft_itoa.c \
	   ft_ltoa.c \
	   ft_lltoa.c \
	   ft_strcpy.c \
	   ft_ulltoa.c \
	   ft_lltoa_hlp.c \
	   ft_strcat.c \
	   ft_strjoin.c \
	   easy_joiner.c \
	   ft_memset.c \
	   ft_strappend.c \
	   ft_strdel.c \
	   spc_string.c \
	   str_add_prefix.c \
	   ft_lstnew.c \
	   ft_lstappend.c \
	   ft_lstdel.c \
	   ft_memcpy.c \
	   ft_putstr.c \
	   ft_strchr.c \
	   ft_atoi.c \
	   ft_strsub.c \
	   ft_isdigit.c \
	   ft_strdup.c \
	   ft_memset.c
TOOLS_SRCS := $(addprefix $(TD),$(TF))

GEN_LOGIC_SRCS := ft_printf.c \
				  format_parser.c \
				  split_str.c \
				  decimals.c \
				  freshers.c
SRCS := $(TOOLS_SRCS) $(GEN_LOGIC_SRCS)

OBJS := $(SRCS:%.c=%.o)

DEPS_DIR := includes/
DEPS_FILES := ft_printf.h ft_printf_helpers.h ft_tools.h
DEPS := $(addprefix $(DEPS_DIR),$(DEPS_FILES))

KEYS := -Wall -Werror -Wextra -g
# delete -g

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(DEPS)
	gcc $(KEYS) -c -o $@ $< -I./$(DEPS_DIR)

link: $(NAME) main.c
	gcc $(KEYS) -o main main.c -L. -lftprintf -I./$(DEPS_DIR)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean
	make

.PHONY: clean fclean re all
