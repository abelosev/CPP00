NAME = megaphone

# Sources (нужно убрать папку SRC_DIR)

SRC_DIR = ./

SRC = 	megaphone.cpp

# Objects

OBJ_DIR = ./obj

OBJ		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Compilation

CC		= g++
CF		= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -g -o $(NAME) $(OBJ)
	@echo "$(NAME) is ready!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CF) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

# Cleaning

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects and dependend files removed."

fclean:	clean
	@rm -rf $(NAME)
	@echo "Binary files removed."

re: fclean all

.PHONY:	all clean fclean re

# изменить это :  использовать $(OBJ_DIR) напрямую в правилах (не создавать отдельно)