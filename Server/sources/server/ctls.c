/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <malloc.h>
#include <unistd.h>
#include "client.h"
#include "input.h"
#include "ctls.h"

int client_ctl(__client_ctl_op op, const int32_t fd)
{
    return ((op == CLIENT_CTL_ADD) ? add_client(fd) :
        (op == CLIENT_CTL_DEL) ? remove_client(fd) : 0);
}

int input_ctl(__command_ctl_op op, const int32_t fd,
const char *const buffer, char **res)
{
    __client_t *client = NULL;
    char *pop_res = NULL;
    int push_res = 0;

    client = find_client(fd);
    if (!client)
        return (84);
    if (op == COMMAND_CTL_PUSH) {
        push_res = push_input(client, buffer);
        if (push_res != 0)
            return (84);
    }
    else if (op == COMMAND_CTL_POP) {
        pop_res = pop_input(client);
        if (!pop_res)
            return (84);
        *res = pop_res;
    }
    return (0);
}