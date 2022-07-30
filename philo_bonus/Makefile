CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -pthread
MAKE		= /bin/make

NAME		= philo_bonus

HEADER		= philosopher_bonus.h \
				parsing_bonus.h

SRC_NAMES	= main_bonus \
				phi_create_thread_bonus \
				phi_error_bonus \
				phi_free_bonus \
				phi_init_philo_bonus \
				phi_init_table_bonus \
				phi_parsing_checker_bonus \
				phi_parsing_setter_bonus \
				phi_parsing_bonus\
				phi_print_bonus \
				phi_routine_action_bonus \
				phi_routine_bonus \
				phi_routine_loop_cond_bonus \
				phi_utils_bonus


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
