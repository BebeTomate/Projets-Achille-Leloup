##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	Lib/flags.c	\
		Lib/my_put_nbr.c	\
		Lib/my_revstr.c	\
		Lib/f_printf.c	\
		Lib/s_printf.c	\
		Lib/e_printf.c	\
		Lib/b_printf.c	\
		Lib/u_printf.c	\
		Lib/my_getnbr.c \
		Lib/g_printf.c  \
		Lib/flags2.c    \
		Lib/switch_cases.c      \
		Lib/switch_cases_flags.c        \
		Lib/my_printf.c

PATHH	=	-I Include/

TESTS	=	tests/test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_printf

CRITERION	=	--coverage -lcriterion

PATHLIB	=	-L -lmy

LIB_NAME	=	libmy.a

H_NAME	=	my_printf.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIB_NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f Lib/*~
	@rm -f Lib/*#*
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
	$(CC) -o unit_tests $(SRC) $(TESTS) $(CRITERION)

tests_run: $(NAME)
	@make unit_tests
	@./unit_tests

gcovr:
	gcovr --exclude tests/ --html-details web/web
