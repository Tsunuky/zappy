/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include "client.h"
#include "input.h"

int push_input(__client_t *client, const char *const buffer)
{
    int cmds = commands_amount(client);

    if (cmds == 10)
        return (0);
    else if (cmds == -1)
        cmds = 0;
    client->__commands[cmds] = strdup(buffer);
    if (!client->__commands[cmds])
        return (84);
    for (uint32_t i = 0; i < (sizeof(client->__commands) /
        sizeof(client->__commands[0])); i++)
        dprintf(1, "%s\n", client->__commands[i]);
    return (0);
}

char *pop_input(__client_t *client)
{
    char *res = NULL;
    int32_t end = 0;

    if (!client->__commands)
        return NULL;
    end = commands_amount(client);
    if (!(res = client->__commands[0]))
        return NULL;
    for (int32_t cpt = 0; cpt != end; cpt++)
        client->__commands[cpt] = client->__commands[cpt + 1];
    client->__commands[end] = NULL;
    return res;
}