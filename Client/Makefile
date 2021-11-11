##
## EPITECH PROJECT, 2020
## zappy
## File description:
## zappy
##

CC				=			g++
RM				=			rm -rvf

OUT				=			zappy_ai
OUTTESTS		=			tests.out

SRCMAIN			=			./main.cpp

GDIR			=			./sources/Graphic/

SRCS			+=			./sources/Client.cpp
SRCS			+=			./sources/Arg.cpp
SRCS			+=			./sources/Ai.cpp
SRCS			+=			./sources/Inventory.cpp
SRCS 			+= 			./sources/Communication.cpp
SRCS 			+= 			./sources/Queue.cpp
SRCS			+=			$(GDIR)Sprite.cpp
SRCS			+=			$(GDIR)device.cpp

SRCSTESTS		+=

CPPFLAGS		=			-O0 -g -W -Wall -Wextra -std=gnu++14
CPPFLAGS		+=			-fprofile-arcs -ftest-coverage -fPIC
CPPFLAGS		+=			-I./includes -I./includes/Graphic

CFLAGS			=			--coverage -lgcov -lpthread
CFLAGS			+=			-lsfml-graphics -lsfml-window -lsfml-system

TESTSFLAGS		=			-lcriterion -ggdb -g3
TESTSFLAGS		+=			-lgcov --coverage
TESTSFLAGS		+=			$(CFLAGS)

OBJS			=			$(SRCS:.cpp=.o)
OBJMAIN			=			$(SRCMAIN:.cpp=.o)
OBJTESTS		=			$(SRCSTESTS:.cpp=.o)
ALLOBJS			=			$(OBJS) $(OBJMAIN) $(OBJTESTS)

GCFILES			+=			$(ALLOBJS:.o=.gcda)
GCFILES			+=			$(ALLOBJS:.o=.gcno)

%.o: %.cpp
	@printf "[\033[0;33m====\033[0m]% 60s\r" $< | tr " " "."
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "[\033[0;32m====\033[0m]% 60s\n" $< | tr " " "."

all : $(OBJS) $(OBJMAIN)
	@printf "[\033[0;33m====\033[0m]% 60s\r" $(OUT) | tr " " "."
	@$(CC) $(CFLAGS) -o $(OUT) $(OBJMAIN) $(OBJS)
	@printf "[\033[0;32m====\033[0m]% 60s\n" $(OUT) | tr " " "."

clean :
	@printf "[\033[0;33m####\033[0m]% 60s\r" $(OBJS) $(OBJMAIN) $(OBJTESTS) $(GCFILES) | tr " " "."
	@$(RM) $(OBJS) $(OBJMAIN) $(OBJTESTS) $(GCFILES) > /dev/null
	@printf "[\033[0;31m####\033[0m]% 60s\n" $(OBJS) $(OBJMAIN) $(OBJTESTS) $(GCFILES) | tr " " "."

fclean : clean
	@printf "[\033[0;33m####\033[0m]% 60s\r" $(OUT) $(OUTTESTS) | tr " " "."
	@$(RM) $(OUT) $(OUTTESTS) > /dev/null
	@printf "[\033[0;31m####\033[0m]% 60s\n" $(OUT) $(OUTTESTS) | tr " " "."

re : fclean all

tests_run : fclean all $(OBJTESTS)
	@printf "[\033[0;32m====\033[0m]% 60s\r" $(OUTTESTS) | tr " " "."
	@$(CC) $(TESTSFLAGS) -o $(OUTTESTS) $(OBJTESTS) $(OBJS)
	@printf "[\033[0;32m====\033[0m]% 60s\n" $(OUTTESTS) | tr " " "."
	@printf "[\033[0;32m====\033[0m]% 60s\r" | tr " " "."
	@./$(OUTTESTS) --verbose
	@gcovr -r .
	@gcovr -b -r . --exclude tests

.PHONY : all clean fclean re tests_run
