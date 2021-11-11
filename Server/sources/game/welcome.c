/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "game.h"

__graphicclt_t *__graphicclt = NULL;

static int welcome_graphic(const int32_t fd)
{
    if (!__graphicclt) {
        if (!(__graphicclt = malloc(sizeof(__graphicclt_t))))
            return (84);
        memset(__graphicclt, 0, sizeof(__graphicclt_t));
        if (!(__graphicclt->__team = malloc(sizeof(__team_t))))
            return (84);
        __graphicclt->__team->__name = "GRAPHIC";
        __graphicclt->__gcfd = fd;
        //add to epoll_ctl
        return (0);
    }
    else {
        dprintf(fd, "GRAPHIC team cannot contain more than one client\n");
        return (-1);
    }
    return (0);
}

static int welcome_team(char *team, const int32_t fd)
{
    /*
    for (int32_t cpt = 0; cpt < __team_arr->__size; cpt++) {
        if (strncmp(__team_arr->__teams[cpt]->__name, team, strlen(team)) == 0) {
            if (__team_arr->__teams[cpt]->__remaining >= 1) {
                __team_arr->__teams[cpt]->__remaining -= 1;
                //random client number
                //print client number
                //random x y
                //print x y
                return (0);
            }
        }
    }
    */
    dprintf(fd, "%s team not found\n", team);
    return (-1);
}

int welcome(const int32_t fd)
{
    char *team = NULL;
    size_t len = 0;
    ssize_t rd = 0; 

    dprintf(fd, "WELCOME\n");
    if ((rd = getline(&team, &len, fdopen(fd, "r"))) < 0)
        return (84);
    team[rd - 1] = '\0';
    if (strcmp(team, "GRAPHIC") == 0)
        return (welcome_graphic(fd));
    else
        return (welcome_team(team, fd));
    return (0);
}