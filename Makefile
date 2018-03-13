# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:47:27 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/13 15:04:57 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Libftp.mk
include $(FT_DIR)/Pretty.mk

RM			 := rm -rf
AR			 := ar
CC			 := gcc
ARFLAGS		 := rc
CFLAGS		 := -Wall -Werror -Wextra
MFLAGS		 := --no-print-directory -C

all: $(FTP_NAME)

# Compile only ft_printf objs. Dont forget to compile libft before
# call this target.
obj: $(FTP_OBJS)

$(FTP_NAME): $(FT_OBJS) $(FTP_OBJS)
	@$(call MKLIB_P,$(@:%=$(RPTH)/%))
	@$(AR) $(ARFLAGS) $(FTP_NAME) $?
	@ranlib $(FTP_NAME)
	@$(call DONE_P)

$(FT_OBJS_DIR)/%.o: $(FT_DIR)/%.c $(FT_DEPS)
	@$(call SUBMAKE_P,$(FT_DIR))
	@$(MAKE) obj RPTH=$(FT_DIR) $(MFLAGS) $(FT_DIR)

# Print: "./" is omited in $@ so simply add RPTH at beginning.
$(FTP_OBJS_DIR)/%.o: $(FTP_SRCS_DIR)/%.c $(FTP_DEPS) $(FT_DEPS)
	@$(call COMPILE_P,$(@:%=$(RPTH)/%))
	@$(CC) $(CFLAGS) -o $@ -c $< -I./$(FTP_DEPS_DIR) -I./$(FT_DEPS_DIR)

$(FTP_OBJS): |$(FTP_OBJS_DIRS)

$(FTP_OBJS_DIRS):
	@$(call DIR_CREATE_P,$(@:%=$(RPTH)/%))
	@mkdir $@

clean:
	@$(RM) $(FTP_OBJS_DIR)
	@$(MAKE) clean $(MFLAGS) $(FT_DIR)
fclean: clean
	@$(RM) $(FTP_NAME)
re: fclean
	@$(MAKE)

.PHONY: clean fclean re all obj
