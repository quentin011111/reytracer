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
		$(MK) --no-print-directory -C ambient/
		$(MK) --no-print-directory -C diffuse/
		$(MK) --no-print-directory -C directional/
		$(MK) --no-print-directory -C drop_shadow/

clean:
		$(MK) $(MKC) --no-print-directory -C ambient/
		$(MK) $(MKC) --no-print-directory -C diffuse/
		$(MK) $(MKC) --no-print-directory -C directional/
		$(MK) $(MKC) --no-print-directory -C drop_shadow/

fclean:
		$(MK) $(MKFC) --no-print-directory -C ambient/
		$(MK) $(MKFC) --no-print-directory -C diffuse/
		$(MK) $(MKFC) --no-print-directory -C directional/
		$(MK) $(MKFC) --no-print-directory -C drop_shadow/

re: fclean all