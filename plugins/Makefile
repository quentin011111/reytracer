##
## EPITECH PROJECT, 2024
## Object-Oriented
## File description:
## Makefile
##

MK		=		make

MKC		=		clean

MKFC	=		fclean

all:
		$(MK) --no-print-directory -C primitives/
		$(MK) --no-print-directory -C lights/

clean:
		$(MK) $(MKC) --no-print-directory -C primitives/
		$(MK) $(MKC) --no-print-directory -C lights/

fclean:
		$(MK) $(MKFC) --no-print-directory -C primitives/
		$(MK) $(MKFC) --no-print-directory -C lights/

re: fclean all