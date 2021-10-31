NAME = 		push_swap
SRC = 		push_swap.c \
			algorythm.c \
			ft_digits_ft.c \
			operations.c \
			operations2.c \
			operations3.c \
			stack.c \
			stack2.c \
			service.c
SRC_DIR =	src
OBJ_DIR	= 	$(SRC_DIR)/obj
INCL = 		-I$(SRC_DIR)/include
C_FLAGS = 	-g #-fsanitize=address -Wall -Wextra -Werror
OBJ = 		$(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $^ $(C_FLAGS) -Llibft -lft -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $< $(C_FLAGS) $(INCL) -Ilibft -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: clean all
