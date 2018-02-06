NAME := libftprintf.a

TD := tools/
TF := ft_strlen.c \
	   ft_strnew.c \
	   ft_itoa.c \
	   ft_ltoa.c \
	   ft_lltoa.c \
	   ft_strcpy.c \
	   ft_ulltoa.c \
	   ft_uimtoa.c \
	   ft_uimtoa_hlp.c \
	   ft_strcat.c \
	   ft_strjoin.c \
	   easy_joiner.c \
	   ft_memset.c \
	   ft_strappend.c \
	   ft_strdel.c \
	   spc_string.c \
	   str_add_prefix.c \
	   ft_lstnew.c \
	   ft_itoabase.c \
	   ft_lstlen.c \
	   ft_lstappend.c \
	   ft_strncpy.c \
	   ft_lstdel.c \
	   ft_memcpy.c \
	   ft_memdup.c \
	   ft_memdel.c \
	   ft_putstr.c \
	   ft_str_realloc.c \
	   ft_strchr.c \
	   ft_itoabase.c \
	   ft_atoi.c \
	   ft_strsub.c \
	   strconnect.c \
	   ft_isdigit.c \
	   ft_strdup.c \
	   ft_lstaddelem.c \
	   ft_memalloc.c \
	   ft_abs.c \
	   ft_memset.c
TOOLS_SRCS := $(addprefix $(TD),$(TF))

GEN_LOGIC_SRCS := ft_printf.c \
				  format_parser.c \
				  split_str.c \
				  get_format_str.c \
				  get_arr_size.c \
				  pos_manager.c \
				  get_data_arr.c \
				  align.c \
				  freshers.c

DECIMAL_DIR := decimals/
DECIMAL_FILES := decimal_flag_except.c \
				 signed_decimals.c \
				 unsigned_decimals.c \
				 dec_ptr_modifiers.c \
				 signed_decimal_modifiers.c \
				 unsigned_decimal_modifiers.c \
				 form_value.c
DECIMAL_LOGIC_SRCS := $(addprefix $(DECIMAL_DIR),$(DECIMAL_FILES))

STRINGS_DIR := strings/
STRINGS_FILES := unicode_to_utf8.c \
				 str_manager.c \
				 str_modifiers.c \
				 ft_witomb.c \
				 chr_manager.c \
				 chr_modifiers.c \
				 wcs_to_utf8.c
STRINGS_LOGIC_SRCS := $(addprefix $(STRINGS_DIR),$(STRINGS_FILES))

SRCS := $(TOOLS_SRCS) $(GEN_LOGIC_SRCS) $(DECIMAL_LOGIC_SRCS) $(STRINGS_LOGIC_SRCS)

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

link: main.o

main.o: main.c $(NAME)
	gcc $(KEYS) -c main.c -I./$(DEPS_DIR)
	gcc $(KEYS) -o main main.o -L. -lftprintf -I./$(DEPS_DIR)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean
	make

.PHONY: clean fclean re all link
