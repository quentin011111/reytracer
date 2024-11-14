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
		$(MK) --no-print-directory -C sphere/
		$(MK) --no-print-directory -C plane/
		$(MK) --no-print-directory -C cylinder/
		$(MK) --no-print-directory -C cone/

clean:
		$(MK) $(MKC) --no-print-directory -C sphere/
		$(MK) $(MKC) --no-print-directory -C plane/
		$(MK) $(MKC) --no-print-directory -C cylinder/
		$(MK) $(MKC) --no-print-directory -C cone/

fclean:
		$(MK) $(MKFC) --no-print-directory -C sphere/
		$(MK) $(MKFC) --no-print-directory -C plane/
		$(MK) $(MKFC) --no-print-directory -C cylinder/
		$(MK) $(MKFC) --no-print-directory -C cone/

re: fclean all