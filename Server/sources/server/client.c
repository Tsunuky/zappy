/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <unistd.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include "client.h"

__client_arr_t *__clients_arr = NULL;

void *find_client(const int32_t fd)
{
    if (__clients_arr->__clients) {
        for (int32_t cpt = 0; cpt < __clients_arr->__size; cpt++)
            if (!__clients_arr->__clients[cpt])
                continue ;
            else if (__clients_arr->__clients[cpt]->__cfd == fd)
                return (__clients_arr->__clients[cpt]);
    }
    return (NULL);
}

int32_t commands_amount(__client_t *client)
{
    char **commands = NULL;
    int32_t res = 0;

    if (client && client->__commands) {
        commands = client->__commands;
        for (int32_t cpt = 0; cpt < 10; cpt++)
            if (commands[cpt] != NULL)
                res++;
        return (res);
    }
    return (-1);
}

int add_client(const int32_t fd)
{
    __clients_arr->__clients = reallocarray(__clients_arr->__clients,
    __clients_arr->__size + 1, sizeof(__client_t *));
    if (!__clients_arr->__clients || !(__clients_arr->
        __clients[__clients_arr->__size] = malloc(sizeof(__client_t))))
        return (84);
    __clients_arr->__clients[__clients_arr->__size]->__cfd = fd;
    __clients_arr->__clients[__clients_arr->__size]->__input_length = 0;
    for (int32_t cpt = 0; cpt < 10; cpt++)
        __clients_arr->__clients[__clients_arr->__size]->
            __commands[cpt] = NULL;
    __clients_arr->__size += 1;
    return (0);
}

int remove_client(const int32_t fd)
{
    if (__clients_arr->__clients) {
        for (int32_t cpt = 0; cpt < __clients_arr->__size; cpt++)
            if (!__clients_arr->__clients[cpt])
                continue;
            else if (__clients_arr->__clients[cpt]->__cfd == fd) {
                free(__clients_arr->__clients[cpt]);
                __clients_arr->__clients[cpt] = NULL;
                close(fd);
            }
    }
    return (0);
}