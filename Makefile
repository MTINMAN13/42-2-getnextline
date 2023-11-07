# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mman <mman@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:54:47 by mman              #+#    #+#              #
#    Updated: 2023/11/07 20:58:12 by mman             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for GET NEXT LINE


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include

# Output file
NAME = get_next_line.a

# Sources
SRC_FILES = get_next_line get_next_line_utils
SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# Commands
RM = rm -f
AR = ar rcs

# Colors
COLOR_RESET = \033[0m
COLOR_RED = \033[0;91m
COLOR_GREEN = \033[0;92m
COLOR_BLUE = \033[0;94m
COLOR_CYAN = \033[0;96m

# Targets
.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN)your mother is a hoe!$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(COLOR_BLUE)Compiling: $<$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(COLOR_CYAN)object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(COLOR_CYAN)executable files cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_GREEN)Cleaned and rebuilt everything!$(COLOR_RESET)"

norm:
