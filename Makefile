# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:47:27 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/11 12:40:41 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
FT_DIR := srcs/libft

include srcs/libft/Colors.mk
include srcs/libft/Libft.mk

DEPS_DIR	:= includes
SRCS_DIR	:= srcs
DG_DIR		:= $(SRCS_DIR)/digits
STR_DIR		:= $(SRCS_DIR)/strings
OBJS_DIR	:= objs
OBJS_DIRS	:= $(OBJS_DIR) $(DG_DIR:$(SRCS_DIR)%=$(OBJS_DIR)%) $(STR_DIR:$(SRCS_DIR)%=$(OBJS_DIR)%)

DEPF		:= ft_printf.h ft_printf_helpers.h ft_structures.h
DG_SRCF		:= digits_flag_except.c \
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
STR_SRCF	 := ft_utu8.c \
				 str_manager.c \
				 str_modifiers.c \
				 ft_witomb.c \
				 chr_manager.c \
				 chr_modifiers.c
M_SRCF		 := ft_printf.c \
				 format_parser.c \
				 split_string.c \
				 get_format_string.c \
				 get_arr_size.c \
				 get_data_arr.c \
				 get_type_arr.c \
				 spaces_handling.c \
				 ptr_manager.c \
				 normalize_full_type.c \
				 ft_memct.c \
				 ft_format.c \
				 ft_memjoin.c \
				 new_gdata.c \
				 new_full_type.c \
				 get_manager_dispatcher.c \
				 string_readers.c \
				 ft_lstaddelem.c \
				 percent_manager.c \
				 logic_type.c \
				 normalize_width.c \
				 get_cur_data.c \
				 outside_param.c \
				 is_type.c \
				 validate_lists.c \
				 freshers.c
M_SRCS		 := $(addprefix $(SRCS_DIR)/,$(M_SRCF))
DG_SRCS		 := $(addprefix $(DG_DIR)/,$(DG_SRCF))
STR_SRCS	 := $(addprefix $(STR_DIR)/,$(STR_SRCF))
SRCS		 := $(M_SRCS) $(DG_SRCS) $(STR_SRCS)
OBJS		 := $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
DEPS		 := $(addprefix $(DEPS_DIR)/,$(DEPF))

RM			 := rm -rf
AR			 := ar
CC			 := gcc
ARFLAGS		 := rc
CFLAGS		 := -Wall -Werror -Wextra
MFLAGS		 := --no-print-directory -C

all: $(NAME)

$(NAME): $(FT_OBJS) $(OBJS)
	@echo "$(GREEN)Making lib ...$(RESET)"
	@$(AR) $(ARFLAGS) $(NAME) $?
	@ranlib $(NAME)
	@echo "$(BOLD)Done !$(RESET)"

$(FT_OBJS_DIR)/%.o: $(FT_DIR)/%.c $(FT_DEPS)
	@$(MAKE) obj $(MFLAGS) $(FT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS) $(FT_DEPS)
	@echo "$(MAGENTA)Compile: $(RESET)$(UNDERLINE)$(GRAY)$@$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $< -I./$(DEPS_DIR) -I./$(FT_DEPS_DIR)

$(OBJS): |$(OBJS_DIRS)

$(OBJS_DIRS):
	@echo "$(GREEN)$(DBOLD)Dir $(UNDERLINE)$@$(RESET)$(GREEN)$(DBOLD) created.$(RESET)"
	@mkdir $@

clean:
	@echo "$(RED)Dir $(UNDERLINE)$(OBJS_DIR)$(RESET) $(RED)deleted.$(RESET)"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) clean $(MFLAGS) $(FT_DIR)
fclean: clean
	@echo "$(RED)File $(UNDERLINE)$(NAME)$(RESET) $(RED)deleted.$(RESET)"
	@$(RM) $(NAME)
re: fclean
	@$(MAKE)

.PHONY: clean fclean re all
