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
		$(MK) --no-print-directory -C src/
		$(MK) --no-print-directory -C plugins/

core:
		$(MK) --no-print-directory -C src/

core_clean:
		$(MK) $(MKC) --no-print-directory -C src/

plugins:
	$(MK) --no-print-directory -C plugins/

plugins_clean:
	$(MK) $(MKC) --no-print-directory -C plugins/

clean:
		$(MK) $(MKC) --no-print-directory -C src/
		$(MK) $(MKC) --no-print-directory -C plugins/

fclean:
		$(MK) $(MKFC) --no-print-directory -C src/
		$(MK) $(MKFC) --no-print-directory -C plugins/

re: fclean all
