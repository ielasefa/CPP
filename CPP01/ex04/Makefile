SRC = main.cpp 

NAME = replace

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Werror -Wextra -std=c++98 

CC = c++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re