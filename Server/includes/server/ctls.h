/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef CTLS_H_
#define CTLS_H_

#include <stdint.h>

typedef enum client_ctl_type
{
    CLIENT_CTL_ADD,
    CLIENT_CTL_DEL
} __client_ctl_op;

typedef enum command_ctl_type
{
    COMMAND_CTL_PUSH,
    COMMAND_CTL_POP
} __command_ctl_op;

int client_ctl(__client_ctl_op, const int32_t);
int input_ctl(__command_ctl_op, const int32_t, const char *const, char **);

#endif
