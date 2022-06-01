# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:47:27 by vpericat          #+#    #+#              #
#    Updated: 2022/05/17 16:04:17 by vpericat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sedisforlosers
PROJECT_NAME = SEDISFORLOSERS

#FILES
SOURCES = main.cpp
HEADERS = 
OBJECTS = $(SOURCES:.cpp=.o)

#MISCELLANEOUS
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

##	VISUALS	##
_BANNER = \033[1m\033[34m[$(PROJECT_NAME)]\033[39m
_BUILDBANNER = $(_BANNER)\033[32m[BUILD]\033[39m —\033[0m
_CLEANBANNER = $(_BANNER)\033[33m[REMOVED]\033[39m —\033[0m

##	RULES	##
all: $(NAME)

%.o: %.cpp Makefile $(HEADERS)
	@$(CC) $(CFLAGS) $(PREPROCFLAGS) -c $< -o $@
	@echo "$(_BUILDBANNER) $@"

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo "$(_BUILDBANNER) $@"

clean:
	@rm -rf $(OBJECTS)
	@echo "$(_CLEANBANNER) object file(s)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(_CLEANBANNER) $(NAME)"
	
re: fclean all

test: all clean
	./sedisforlosers testfiles/flam.test "Capitaine Flam" "Philippe Etchebest"
	./sedisforlosers testfiles/hitchhiker.test "Universe" "42"
	./sedisforlosers testfiles/motordu.test Motordu "Darth Vader"
	./sedisforlosers testfiles/queen.test "Don't stop me" "I'm sleepy"
	diff testfiles/hitchhiker.test testfiles/hitchhiker.test.replace > hitchhiker.diff
	diff testfiles/flam.test testfiles/flam.test.replace > flam.diff
	diff testfiles/motordu.test testfiles/motordu.test.replace > motordu.diff
	diff testfiles/queen.test testfiles/queen.test.replace > queen.diff

nice: all clean
	@clear

.PHONY: clean fclean all re nice test
