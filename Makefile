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


all: $(NM) $(OBJDUMP)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CC=gcc
tests: $(TEST)

tests_run: tests
	@./$(TEST)

$(NM):
	@$(MAKE) -C nm/
	ln -f nm/nm $(NM)

$(OBJDUMP):
	@$(MAKE) -C objdump/
	ln -f objdump/objdump $(OBJDUMP)

clean:
	@$(MAKE) clean -C nm/
	@$(MAKE) clean -C objdump/

fclean:
	@$(MAKE) fclean -C nm/
	@$(MAKE) fclean -C objdump/
	@$(RM) $(NM) $(OBJDUMP)

re: fclean all

.PHONY: all clean fclean re debug tests
