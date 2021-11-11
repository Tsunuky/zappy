/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stddef.h>
#include <stdio.h>

const char *const port = "port\t\tport number";
const char *const width = "width\t\twidth of the world";
const char *const height = "height\t\theight of the world";
const char *const name = "nameX\t\tname of the team X";
const char *const clients = "clientsNb\tnumber of authorized clients per team";
const char *const freq = "freq\t\treciprocal of time unit for execution \
of actions";
const char *const usage = "USAGE : %s -p port -x width -y height \
-n name1 name2 ... -c clientsNb \
-f freq\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n";

int help(const char *const bin)
{
    char *help = NULL;

    asprintf(&help, usage, bin, port, width, height, name, clients, freq);
    dprintf(fileno(stdout), "%s", help);
    return (0);
}