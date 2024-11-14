##
## EPITECH PROJECT, 2024
## Object-Oriented
## File description:
## Makefile
##

RED			=	\e[31m
GREEN		=	\e[32m
YELLOW		=	\e[33m
DEFAULT		=	\e[0m
BOLD		=	\e[1m

#TEXTS
COMPILE = $$'$(BOLD)$(GREEN)[The project is compiled !]\t$(DEFAULT)'
RE_COMPILE = $$'$(BOLD)$(GREEN)[The project is recompiled !]\t$(DEFAULT)'
CLEAN = $$'$(BOLD)$(RED)[The useless files are removed !]\t$(DEFAULT)'
FCLEAN =$$'$(BOLD)$(RED)[All old created files have been deleted !]\t$(DEFAULT)'

#SHORTCUTS
NAME			=	raytracer

SRC				=	$(shell find -name "*.cpp")

OBJ				= 	$(SRC:.cpp=.o)

CFLAGS			=	-std=c++20 -g3 -lX11 -lconfig++ -lsfml-graphics -lsfml-window -lsfml-system

WERROR_FLAG		= -fno-gnu-unique -Werror -Wall -Wextra


#RULES
all:	$(NAME)

$(NAME):
	@g++ -o $(NAME) $(SRC) $(CFLAGS) $(WERROR_FLAG)
	mv $(NAME) ../
	@echo $(COMPILE)

%.o: %.cpp
	@g++ -o $@ -c $< -g

clean:
	@rm -f $(OBJ)
	@echo $(CLEAN)

fclean: clean
	@rm -f ../$(NAME)
	@echo $(FCLEAN)

re: fclean all
	@echo $(RE_COMPILE)

.PHONY: all clean fclean re