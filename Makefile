##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## Makefile
##

CC		=	gcc

NAME		=	nm

RM		=	rm -vf

MAIN		=	src/main.cpp

SRCS		=

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CFLAGS	=	-W -Wextra -Wall -I include/ -std=c++17

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
	@$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	@$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re debug tests
