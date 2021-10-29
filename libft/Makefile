# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkocob <dkocob@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/25 13:57:19 by dkocob        #+#    #+#                  #
#    Updated: 2021/10/21 21:59:43 by dkocob        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	ft_putstring.c 

SRC_DIR =	src
OBJ_DIR =	$(SRC_DIR)/obj
INCL =		-I.
CFLAGS = -Wall -Wextra -Werror
CC = clang

O_FILES = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@$(AR) -r $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $@
	@$(CC) -c $(CFLAGS) $(INCL) -o $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test