NAME =		tests

CFLAGS =	-Wall -Werror -Wextra -std=c++11

SRC =		Account.cpp tests.cpp

BLUE =		\033[0;34m
GREEN =		\033[0;32m
RESET =		\033[0m

OBJ =		${SRC:.cpp=.o}

%.o: %.cpp
	@clang++ $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ)
		@echo "$(BLUE)Building $(NAME)...$(RESET)"
		clang++ $(OBJ) -o $(NAME)
		@echo "$(GREEN)$(NAME) built$(RESET)"

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re