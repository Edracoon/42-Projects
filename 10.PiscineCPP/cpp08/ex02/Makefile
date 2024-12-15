NAME =		mutantstack

CXX	 =		clang++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =		$(wildcard *.cpp)

OBJS =		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:
			rm -rf $(OBJS)
			rm -rf $(NAME)

re:			fclean all

.PHONY:		re clean fclean all