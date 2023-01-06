NAME = ex03
PROJECT_NAME = EX03

#FILES
FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

#OBJECTS
OBJS = $(FILES:.cpp=.o)

#MISCELLANEOUS
DEBUGFLAGS =#-DDEBUG
PREPROCFLAGS = $(DEBUGFLAGS)
LINKERFLAGS = $(DEBUGFLAGS)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 $(DEBUGFLAGS)

##	VISUALS	##
_BANNER = \033[1m\033[34m[$(PROJECT_NAME)]\033[39m
_BUILDBANNER = $(_BANNER)\033[32m[BUILD]\033[39m —\033[0m
_CLEANBANNER = $(_BANNER)\033[33m[REMOVED]\033[39m —\033[0m

##	RULES	##
all:  $(NAME)

%.o: %.cpp $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(PREPROCFLAGS) -c $< -o $@
	@echo "$(_BUILDBANNER) $@"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LINKERFLAGS)
	@echo "$(_BUILDBANNER) $@"

clean:
	@rm -rf $(OBJS)
	@echo "$(_CLEANBANNER) object files"

	
fclean: clean
	@rm -f $(NAME)
	@echo "$(_CLEANBANNER) $(NAME)"
	
re: fclean all

nice: all clean
	@clear
	@echo "\033[34m\033[1m[NICE]\033[39m —\033[0m clear"

.PHONY: clean fclean all re nice
