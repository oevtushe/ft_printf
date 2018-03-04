# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:47:27 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/04 12:38:19 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	   ft_memct.c \
	   ft_memalloc.c \
	   ft_memjoin.c \
	   ft_memchr.c \
	   ft_memset.c

# Strings Tools

ST := ft_strnew.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strjoin.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strcmp.c \
	   ft_strtoupper.c \
	   ft_strlen.c \
	   ft_strsub.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_str_realloc.c \
	   ft_imtoabase.c \
	   ft_strconnect.c \
	   ft_strcntllr.c

# List Tools

LT := ft_lstnew.c \
	   ft_lstaddelem.c \
	   ft_lstappend.c \
	   ft_lstdel.c

# Other Tools

OT := ft_uimtoabase_gen.c \
	   ft_putstr_ln.c \
	   ft_atoi.c \
	   ft_spsign.c \
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
			  split_string.c \
			  get_format_string.c \
			  get_arr_size.c \
			  get_data_arr.c \
			  get_type_arr.c \
			  spaces_handling.c \
			  ptr_manager.c \
			  normalize_full_type.c \
			  ft_format.c \
			  new_gdata.c \
			  new_full_type.c \
			  get_manager_dispatcher.c \
			  string_readers.c \
			  percent_manager.c \
			  logic_type.c \
			  normalize_width.c \
			  get_color_code.c \
			  get_cur_data.c \
			  color_parser.c \
			  outside_param.c \
			  is_type.c \
			  validate_lists.c \
			  freshers.c



#########################################################################################
#																						#
# 										DIGITS  	  									#
#																						#
#########################################################################################



DIGITS_DIR := digits/
DIGITS_FILES := digits_flag_except.c \
				 signed_decimals.c \
				 unsigned_decimals.c \
				 octal_manager.c \
				 group_by_thousands.c \
				 signed_gdata_load.c \
				 binary_manager.c \
				 ft_group_by.c \
				 hex_manager.c \
				 signed_decimal_modifiers.c \
				 unsigned_decimal_modifiers.c \
				 zeroes_handling.c
DIGITS_SRCS := $(addprefix $(DIGITS_DIR),$(DIGITS_FILES))



#########################################################################################
#																						#
# 										STRINGS  	  									#
#																						#
#########################################################################################



STRINGS_DIR := strings/
STRINGS_FILES := ft_utu8.c \
				 str_manager.c \
				 str_modifiers.c \
				 ft_witomb.c \
				 chr_manager.c \
				 chr_modifiers.c
STRINGS_SRCS := $(addprefix $(STRINGS_DIR),$(STRINGS_FILES))



#########################################################################################
#																						#
# 										  MAKE  	  									#
#																						#
#########################################################################################

COLOR_RED := \033[32;1;31m
COLOR_GREEN := \033[32;1;40m
COLOR_VIOLET := \033[35;1;40m
END_COLOR := \033[0m

SRCS := $(TOOLS_SRCS) $(MAIN_SRCS) $(DIGITS_SRCS) $(STRINGS_SRCS)

OBJECTS := $(SRCS:%.c=%.o)

DEPENDENCY_DIR := includes/
DEPENDENCY_FILES := ft_printf.h ft_printf_helpers.h ft_tools.h ft_structures.h
DEPENDENCY := $(addprefix $(DEPENDENCY_DIR),$(DEPENDENCY_FILES))

KEYS :=  -Wall -Werror -Wextra -g
# delete -g

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(COLOR_GREEN)Making lib ...$(END_COLOR)"
	@ar -rc $(NAME) $(OBJECTS)
	@echo "$(COLOR_RED)Indexation ...$(END_COLOR)"
	@ranlib $(NAME)

%.o: %.c $(DEPENDENCY)
	@echo "$(COLOR_VIOLET)Compiling obj: $@$(END_COLOR)"
	@gcc $(KEYS) -c -o $@ $< -I./$(DEPENDENCY_DIR)

link_extra: printf_main.o

printf_main.o: printf_main.c $(NAME)
	gcc $(KEYS) -c printf_main.c -I./$(DEPENDENCY_DIR)
	gcc $(KEYS) -o printf_main printf_main.o -L. -lftprintf -I./$(DEPENDENCY_DIR)

link: main.o

main.o: main.c $(NAME)
	gcc $(KEYS) -c main.c -I./$(DEPENDENCY_DIR)
	gcc $(KEYS) -o main main.o -L. -lftprintf -I./$(DEPENDENCY_DIR)
clean:
	@echo "$(COLOR_RED)Deleting obj files ...$(END_COLOR)"
	@rm -f $(OBJECTS)
fclean: clean
	@echo "$(COLOR_RED)Deleting $(NAME) ...$(END_COLOR)"
	@rm -f $(NAME)
re: fclean
	@echo "$(COLOR_RED)Deleting $(NAME) ...$(END_COLOR)"
	@make

.PHONY: clean fclean re all link
