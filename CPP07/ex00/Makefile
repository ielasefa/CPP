NAME =	whatever
CC =	c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re