COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = containers

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)
	@echo "Compiled successfully."

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.txt


re: fclean all


test: re
	./$(NAME)


.PHONY: all clean fclean re test
