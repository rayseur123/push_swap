NAME := push_swap

SRCS := push_swap.c \
		instruction.c \
		instruction2.c \
		parsing.c \
		parsing2.c \
		sorting.c \
		manage_lst.c \
		manage_stack_sort.c \
		pre_sorting.c \
		search_sort.c \

SRCS_BONUS := 	checker.c \
				handle_checker.c \
				checker_manage.c \
				instruction.c \
				instruction2.c \
				parsing.c \
				parsing2.c \
				manage_lst.c \

UTILS := utils

OBJS := $(addprefix $(UTILS)/,$(SRCS:.c=.o))
OBJS_B := $(addprefix $(UTILS)/,$(SRCS_BONUS:.c=.o))
DEPS := $(addprefix $(UTILS)/,$(SRCS:.c=.d))
DEPS_B := $(addprefix $(UTILS)/,$(SRCS_BONUS:.c=.d))


LIBS := -Llibft/ -lft
PATH_LIBS := libft/
INCLUDE_DIRS := -I libft/include

CC = cc
CPPFLAGS := -MMD -MP -g3 $(INCLUDE_DIRS)
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $^ -o $@

$(UTILS)/%.o: %.c | $(UTILS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(UTILS):
	@mkdir -p $(UTILS)

$(LIBS):
	$(MAKE) -C $(PATH_LIBS)

-include $(DEPS)

bonus: $(OBJS_B) $(LIBS)
		$(CC) $^ -o checker

clean:
	$(MAKE) clean -C lib/libft/
	rm -f $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C lib/libft/
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re