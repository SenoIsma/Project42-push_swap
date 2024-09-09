NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS = $(SRCS_DIR)/ft_clear.c \
		$(SRCS_DIR)/ft_split.c \
		$(SRCS_DIR)/ft_verif.c \
		$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/mouvements.c \
		$(SRCS_DIR)/parsing.c \
		$(SRCS_DIR)/utils.c \

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re