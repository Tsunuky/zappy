##
## EPITECH PROJECT, 2020
## zappy
## File description:
## zappy
##

CC				=			gcc
RM				=			rm -rvf

OUT				=			zappy_server
OUTTESTS		=			tests.out

SRCMAIN			=			./main.c

SRCS			+=			./sources/core.c
SRCS			+=			./sources/args/args.c
SRCS			+=			./sources/args/check.c
SRCS			+=			./sources/args/parser.c
SRCS			+=			./sources/args/help.c
SRCS			+=			./sources/program/constructor.c
SRCS			+=			./sources/program/destructor.c
SRCS			+=			./sources/server/server.c
SRCS			+=			./sources/server/loop.c
SRCS			+=			./sources/server/client.c
SRCS			+=			./sources/server/new.c
SRCS			+=			./sources/server/ctls.c
SRCS			+=			./sources/server/input.c
SRCS			+=			./sources/server/processing/commands.c
SRCS			+=			./sources/server/processing/protocol.c
SRCS			+=			./sources/server/processing/parser.c
SRCS			+=			./sources/server/processing/commands/broadcast.c
SRCS			+=			./sources/server/processing/commands/connect.c
SRCS			+=			./sources/server/processing/commands/eject.c
SRCS			+=			./sources/server/processing/commands/fork.c
SRCS			+=			./sources/server/processing/commands/forward.c
SRCS			+=			./sources/server/processing/commands/incantation.c
SRCS			+=			./sources/server/processing/commands/inventory.c
SRCS			+=			./sources/server/processing/commands/left.c
SRCS			+=			./sources/server/processing/commands/look.c
SRCS			+=			./sources/server/processing/commands/right.c
SRCS			+=			./sources/server/processing/commands/set.c
SRCS			+=			./sources/server/processing/commands/take.c
SRCS			+=			./sources/server/processing/protocol/bct.c
SRCS			+=			./sources/server/processing/protocol/ebo.c
SRCS			+=			./sources/server/processing/protocol/edi.c
SRCS			+=			./sources/server/processing/protocol/eht.c
SRCS			+=			./sources/server/processing/protocol/enw.c
SRCS			+=			./sources/server/processing/protocol/mct.c
SRCS			+=			./sources/server/processing/protocol/msz.c
SRCS			+=			./sources/server/processing/protocol/pbc.c
SRCS			+=			./sources/server/processing/protocol/pdi.c
SRCS			+=			./sources/server/processing/protocol/pdr.c
SRCS			+=			./sources/server/processing/protocol/pex.c
SRCS			+=			./sources/server/processing/protocol/pfk.c
SRCS			+=			./sources/server/processing/protocol/pgt.c
SRCS			+=			./sources/server/processing/protocol/pic.c
SRCS			+=			./sources/server/processing/protocol/pie.c
SRCS			+=			./sources/server/processing/protocol/pin.c
SRCS			+=			./sources/server/processing/protocol/plv.c
SRCS			+=			./sources/server/processing/protocol/pnw.c
SRCS			+=			./sources/server/processing/protocol/ppo.c
SRCS			+=			./sources/server/processing/protocol/sbp.c
SRCS			+=			./sources/server/processing/protocol/seg.c
SRCS			+=			./sources/server/processing/protocol/sgt.c
SRCS			+=			./sources/server/processing/protocol/smg.c
SRCS			+=			./sources/server/processing/protocol/sst.c
SRCS			+=			./sources/server/processing/protocol/suc.c
SRCS			+=			./sources/server/processing/protocol/tna.c
SRCS			+=			./sources/game/map.c
SRCS			+=			./sources/game/player.c
SRCS			+=			./sources/game/team.c
SRCS			+=			./sources/game/welcome.c

SRCSTESTS		+=			./tests/test_program.c
SRCSTESTS		+=			./tests/test_args.c

CPPFLAGS		=			-O0 -g -W -Wall -Wextra -std=gnu99
CPPFLAGS		+=			-fprofile-arcs -ftest-coverage -fPIC
CPPFLAGS		+=			-I./includes -I./includes/server
CPPFLAGS		+=			-I./includes/server/processing
CPPFLAGS		+=			-D _GNU_SOURCE

CFLAGS			=			--coverage -lgcov

TESTSFLAGS		=			-lcriterion -ggdb -g3
TESTSFLAGS		+=			-lgcov --coverage

OBJS			=			$(SRCS:.c=.o)
OBJMAIN			=			$(SRCMAIN:.c=.o)
OBJTESTS		=			$(SRCSTESTS:.c=.o)
ALLOBJS 		= 			$(OBJS) $(OBJMAIN) $(OBJTESTS)

GCFILES 		+= 			$(ALLOBJS:.o=.gcda)
GCFILES 		+= 			$(ALLOBJS:.o=.gcno)

%.o: %.c
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
	@gcovr -r . --exclude tests
	@gcovr -b -r . --exclude tests

.PHONY : all clean fclean re tests_run
