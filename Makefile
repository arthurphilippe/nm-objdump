##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME		=	nm

MAIN		=	src/main.c

SRCS		=

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CXX=g++
tests: $(TEST)

tests_run: tests
	@./$(TEST)

$(NAME): $(OBJ_MAIN) $(OBJS)
	@$(CXX) $(OBJ_MAIN) $(OBJS) -o $(NAME)
	@echo " --> $(NAME) built!"

$(TEST): $(OBJS_TEST)
	@$(CXX) $(OBJS_TEST) -o $(TEST) -lcriterion
	@echo " --> $(TEST) built!"
clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re debug tests
