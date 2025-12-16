NAME = now_were_taiking

DFLAGS = -g -fsanitize=address -fsanitize=leak

CLANGD_TEMPLATE := ~/.config/clangd_templates/default.clangd
CLANGD_TARGET := .clangd

SRC_DIR = ./

SRC_FILES = Fixed.cpp main.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

TEST_DIR = tests/
TEST = test.sh

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

debug: CFLAGS += $(DFLAGS)
debug: clean
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

%.o: %.cpp 
	@$(CC) $(CFLAGS) -c $< -o $@

test: debug
	@bash $(TEST_DIR)$(TEST)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
