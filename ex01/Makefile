NAME = towards_a_more_useful_fixed-point_number_class

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude
LDFLAGS =

SANFLAGS = -g -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer

SRC_DIR = src/
OBJ_DIR = obj/
SRC_FILES = Fixed.cpp main.cpp
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

TEST_DIR = tests/
TEST = test.sh

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: CXXFLAGS += $(SANFLAGS)
debug: LDFLAGS += $(SANFLAGS)
debug: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re test
