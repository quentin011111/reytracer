##
## EPITECH PROJECT, 2024
## Object-Oriented
## File description:
## Makefile
##

NAME	=	../libsphere.so

SRC		=	Sphere.cpp	\
			SphereLib.cpp

OBJS	=	$(SRC:.cpp=.o)

CC		=	g++

RM		=	rm -f

CXXFLAGS 	= 	-Wall -Wextra -Werror -fPIC -shared

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re	:	fclean all

.cpp.o	:
	@$(CC) $(CXXFLAGS) -c -o $@ $<