CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -pthread
MAKE		= /bin/make

NAME		= philo

HEADER		= philosopher.h \
				parsing.h

SRC_NAMES	= philosopher \
				phi_create_thread \
				phi_error \
				phi_free \
				phi_init_philo \
				phi_init_table \
				phi_parsing_checker \
				phi_parsing_setter \
				phi_parsing \
				phi_print \
				phi_print_utils \
				phi_routine_action \
				phi_routine_loop_cond \
				phi_routine \
				phi_utils

OBJ_DIR		= obj

OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m

all:			$(NAME)

clean:
	@echo "$(_GREEN)Removing objects$(_NO_COLOR)"
	rm -f $(OBJ)
	@if [ -d $(OBJ_DIR) ]; then \
		find $(OBJ_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi

fclean:			clean
	rm -f $(NAME)
re:				
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(HEADER) $(OBJ) 
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:%.c $(HEADER)

	@if [ ! -d $(dir $@) ]; then \
		echo "\n$(_CYAN)Create $(dir $@)$(_NO_COLOR)"; \
		mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY:	all clean fclean re
