NAME =		serialisation

CXX	 =		clang++

CXXFLAGS =	-Wall -Wextra -Werror

SRCS =		$(wildcard *.cpp)

OBJS =		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	print $(OBJS)
			@echo "\n\033[32;1;1m=========== Compilation =========="
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\nFinished √ \nProgram name : ./[$(NAME)]\n\033[0m"

print:	
			@echo "\033[32;1;1m========== Object files ==========" 

clean:
			@echo "\033[31;1;1m==== cleaning ... ===="
			rm -rf $(OBJS)
			@echo "\033[0m"

fclean:		
			@echo "\n\033[31;1;1m============= fclean ============="
			rm -rf $(OBJS)
			rm -rf $(NAME)
			@echo "\033[0m"

re:			fclean all

.PHONY:		re clean fclean all