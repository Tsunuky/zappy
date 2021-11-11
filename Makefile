##
## EPITECH PROJECT, 2020
## zappy
## File description:
## zappy
##

CP				=			cp
RM				=			rm -rvf

CLIENTOUT		=			zappy_ai
SERVEROUT		=			zappy_server

all :
	$(MAKE) -C Client
	$(MAKE) -C Server
	$(CP) ./Client/$(CLIENTOUT) .
	$(CP) ./Server/$(SERVEROUT) .

clean :
	$(MAKE) -C Client clean
	$(MAKE) -C Server clean

fclean : clean
	$(MAKE) -C Client fclean
	$(MAKE) -C Server fclean
	$(RM) ./$(CLIENTOUT)
	$(RM) ./$(SERVEROUT)

re : fclean all
	$(MAKE) -C Client re
	$(MAKE) -C Server re

tests_run : fclean all
	$(MAKE) -C Client tests_run
	$(MAKE) -C Server tests_run

.PHONY : all clean fclean re tests_run
