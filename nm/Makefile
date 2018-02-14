##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME		=	nm

MAIN		=	src/main.c

SRCS		=	src/nm.c			\
			src/set_map_ptr.c		\
			src/elf/elf_set_fields.c	\
			src/elf/elf_validate_format.c	\
			src/elf/elf_populate_32bits.c

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJS		=	$(SRCS:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

%.o: %.c
	@printf "[\033[0;32massembly\033[0m]....%s\n" $<
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

debug: CFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CC=gcc
tests: $(TEST)

tests_run: tests
	@./$(TEST)

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinkage\033[0m].....%s\n" $(NAME)
	@$(CC) $(OBJ_MAIN) $(OBJS) -o $(NAME)
	@echo -e " --> Complete!"

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinkage\033[0m].....%s\n" $(TEST)
	@$(CC) $(OBJS_TEST) -o $(TEST) -lcriterion
	@echo -e " --> Complete!"

clean:
	@echo -en "[\033[0;31mdeletion\033[0m]...." ; $(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'
	@echo " of $(NAME)'s objects"

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@echo -e "[\033[0;31mdeletion\033[0m]....$(NAME)"

re: fclean all

.PHONY: all clean fclean re debug tests
