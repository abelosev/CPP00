NAME = PhoneBook

# Sources

SRC_DIR = ./

SRC = 	./PhoneBook.cpp \
		./Contact.cpp \
		./main.cpp 

# Objects

OBJ_DIR = ./obj

OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Compilation

CC		= g++
CF		= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -g -o $(NAME) $(OBJ)
	@echo "$(NAME) is ready!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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
