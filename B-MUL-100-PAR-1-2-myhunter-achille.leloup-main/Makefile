##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC	=	gcc

BASE_SRC	= 	src/initialisation.c	\
				src/core_functions.c	\
				src/basic_functions_hunter.c	\
				src/other_functions.c	\
				src/misc_function.c	\

SRC	=	$(BASE_SRC) \
		my_hunter.c

SRC_TEST	=	$(BASE_SRC)	\
				tests/test.c

CSFML	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

PATHH	=	-I include

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	(SRC_TEST:.c=.o)

CFLAGS	=	-I include -g

NAME	=	my_hunter

CRITERION	=	--coverage -lcriterion

H_NAME	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CSFML)

clean:
	@rm -f $(OBJ)
	@rm -f src/*~
	@rm -f src/*#*
	@rm -f include/*~
	@rm -f include/*#*
	@rm -f *~
	@rm -f *#*
	@rm -f *gcno
	@rm -f *gcda
	@rm -f unit_tests
	@rm -f tests/*~
	@rm -f tests/*#*
	@rm -f web/*.css
	@rm -f web/*.html
	@rm -f web/web
	@rm -f coding-style-reports.log
	@rm -f libmy.a

fclean: clean
	@rm -f $(NAME)

re:	fclean all

unit_tests: $(NAME)
	$(CC) -o unit_tests $(SRC_TESTS) $(CRITERION)

tests_run: $(NAME)
	@make unit_tests
	@./unit_tests

gcovr:
	gcovr --exclude tests/ --html-details web/web
