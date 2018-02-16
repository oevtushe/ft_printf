NAME := libftprintf.a



#########################################################################################
#																						#
# 										 TOOLS	  	  									#
#																						#
#########################################################################################



TD := tools/

# Memory Tools

MT := ft_memcpy.c \
	   ft_memdup.c \
	   ft_memdel.c \
	   ft_memset.c \
	   ft_memalloc.c \
	   ft_memjoin.c \
	   ft_memset.c

# Strings Tools

ST := ft_strnew.c \
	   ft_strcpy.c \
	   ft_strappend.c \
	   ft_strdel.c \
	   ft_strjoin.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_strsub.c \
	   ft_strncpy.c \
	   ft_strtoupper.c \
	   ft_strcat.c \
	   ft_str_realloc.c \
	   ft_itoa.c \
	   ft_ltoa.c \
	   ft_lltoa.c \
	   ft_ulltoa.c \
	   ft_uimtoa.c \
	   ft_uimtoa_hlp.c \
	   ft_imtoabase.c \
	   str_add_prefix.c \
	   easy_joiner.c \
	   strconnect.c \
	   spc_string.c

# List Tools

LT := ft_lstnew.c \
	   ft_lstlen.c \
	   ft_lstaddelem.c \
	   ft_lstappend.c \
	   ft_lstdel.c

# Other Tools

OT := ft_putstr.c \
	   ft_uimtoabase_gen.c \
	   ft_putstr_ln.c \
	   ft_atoi.c \
	   ft_isdigit.c \
	   ft_abs.c
TOOLS := $(MT) $(ST) $(LT) $(OT)
TOOLS_SRCS := $(addprefix $(TD),$(TOOLS))



#########################################################################################
#																						#
# 										 MAIN	  	  									#
#																						#
#########################################################################################



MAIN_SRCS := ft_printf.c \
			  format_parser.c \
			  split_str.c \
			  get_format_string.c \
			  get_arr_size.c \
			  get_data_arr.c \
			  align.c \
			  ptr_manager.c \
			  ptr_modifiers.c \
			  pos_manager.c \
			  pos_modifiers.c \
			  percent_manager.c \
			  undef_manager.c \
			  freshers.c



#########################################################################################
#																						#
# 										DIGITS  	  									#
#																						#
#########################################################################################



DIGITS_DIR := digits/
DIGITS_FILES := decimal_flag_except.c \
				 signed_decimals.c \
				 unsigned_decimals.c \
				 octal_manager.c \
				 group_by_thousands.c \
				 hex_manager.c \
				 signed_decimal_modifiers.c \
				 unsigned_decimal_modifiers.c \
				 width_and_prec.c
DIGITS_SRCS := $(addprefix $(DIGITS_DIR),$(DIGITS_FILES))



#########################################################################################
#																						#
# 										STRINGS  	  									#
#																						#
#########################################################################################



STRINGS_DIR := strings/
STRINGS_FILES := unicode_to_utf8.c \
				 str_manager.c \
				 str_modifiers.c \
				 ft_witomb.c \
				 chr_manager.c \
				 chr_modifiers.c \
				 wcs_to_utf8.c
STRINGS_SRCS := $(addprefix $(STRINGS_DIR),$(STRINGS_FILES))



#########################################################################################
#																						#
# 										  MAKE  	  									#
#																						#
#########################################################################################



SRCS := $(TOOLS_SRCS) $(MAIN_SRCS) $(DIGITS_SRCS) $(STRINGS_SRCS)
OBJECTS := $(SRCS:%.c=%.o)
DEPENDENCY_DIR := includes/
DEPENDENCY_FILES := ft_printf.h ft_printf_helpers.h ft_tools.h
DEPENDENCY := $(addprefix $(DEPENDENCY_DIR),$(DEPENDENCY_FILES))

KEYS := -Wall -Werror -Wextra -g
# delete -g

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(DEPENDENCY)
	gcc $(KEYS) -c -o $@ $< -I./$(DEPENDENCY_DIR)

link: main.o

main.o: main.c $(NAME)
	gcc $(KEYS) -c main.c -I./$(DEPENDENCY_DIR)
	gcc $(KEYS) -o main main.o -L. -lftprintf -I./$(DEPENDENCY_DIR)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean
	make

.PHONY: clean fclean re all link
