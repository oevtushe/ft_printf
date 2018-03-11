# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:47:27 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/11 14:17:22 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_DIR	:= srcs/libft
FTP_DIR	:= .

include srcs/libft/Colors.mk
include srcs/libft/Libft.mk
include Libftp.mk

RM			 := rm -rf
AR			 := ar
CC			 := gcc
ARFLAGS		 := rc
CFLAGS		 := -Wall -Werror -Wextra
MFLAGS		 := --no-print-directory -C

all: $(FTP_NAME)

$(FTP_NAME): $(FT_OBJS) $(FTP_OBJS)
	@echo "$(GREEN)Making lib ...$(RESET)"
	@$(AR) $(ARFLAGS) $(FTP_NAME) $?
	@ranlib $(FTP_NAME)
	@echo "$(BOLD)Done !$(RESET)"

$(FT_OBJS_DIR)/%.o: $(FT_DIR)/%.c $(FT_DEPS)
	@$(MAKE) obj $(MFLAGS) $(FT_DIR)

$(FTP_OBJS_DIR)/%.o: $(FTP_SRCS_DIR)/%.c $(FTP_DEPS) $(FT_DEPS)
	@echo "$(MAGENTA)Compile: $(RESET)$(UNDERLINE)$(GRAY)$@$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $< -I./$(FTP_DEPS_DIR) -I./$(FT_DEPS_DIR)

$(FTP_OBJS): |$(FTP_OBJS_DIRS)

$(FTP_OBJS_DIRS):
	@echo "$(GREEN)$(DBOLD)Dir $(UNDERLINE)$@$(RESET)$(GREEN)$(DBOLD) created.$(RESET)"
	@mkdir $@

clean:
	@echo "$(RED)Dir $(UNDERLINE)$(FTP_OBJS_DIR)$(RESET) $(RED)deleted.$(RESET)"
	@$(RM) $(FTP_OBJS_DIR)
	@$(MAKE) clean $(MFLAGS) $(FT_DIR)
fclean: clean
	@echo "$(RED)File $(UNDERLINE)$(NAME)$(RESET) $(RED)deleted.$(RESET)"
	@$(RM) $(FTP_NAME)
re: fclean
	@$(MAKE)

.PHONY: clean fclean re all
