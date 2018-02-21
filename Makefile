##
## EPITECH PROJECT, 2018
## nmobjdump
## File description:
## makefile
##

RM		=	rm -vf

NM		=	my_nm

OBJDUMP		=	my_objdump

CFLAGS		=	-W -Wextra -Wall -Iinclude/

ifndef VERBOSE
	MAKEFLAGS	+=	--no-print-directory
endif

all: objdump
all: nm

debug: fclean
	@$(MAKE) debug -C nm/
	@ln -sf nm/nm $(NM)
	@$(MAKE) debug -C objdump/
	@ln -sf objdump/objdump $(OBJDUMP)

tests: CC=gcc
tests:
	@$(MAKE) nm -C nm/
	@ln -sf nm/nm $(NM)
	@$(MAKE) objdump -C objdump/
	@ln -sf objdump/objdump $(OBJDUMP)

tests_run: tests
	@./$(TEST)

nm:
	@$(MAKE) nm -C nm/
	@cp nm/nm $(NM)

objdump:
	@$(MAKE) objdump -C objdump/
	@cp objdump/objdump $(OBJDUMP)

clean:
	@$(MAKE) clean -C nm/
	@$(MAKE) clean -C objdump/

fclean:
	@$(MAKE) fclean -C nm/
	@$(MAKE) fclean -C objdump/
	@$(RM) $(NM) $(OBJDUMP) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][symlinks]% 30s\n" "$(NM)^$(OBJDUMP)" | tr " " "." | tr "^" " "

re: fclean all

.PHONY: all clean fclean re debug tests nm objdump
