/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <malloc.h>
#include <string.h>
#include <stddef.h>
#include "server.h"
#include "client.h"
#include "game.h"
#include "args.h"

static int construct_args(void)
{
    __args = (__args_t *)malloc(sizeof(__args_t));
    if (!__args)
        return (84);
    memset(__args, 0, sizeof(__args_t));
    __args->__names = NULL;
    return (0);
}

static int construct_server(void)
{
    __server = (__server_t *)malloc(sizeof(__server_t));
    if (!__server)
        return (84);
    memset(__server, 0, sizeof(__server_t));
    __server->__server = NULL;
    return (0);
}

static int construct_clients(void)
{
    __clients_arr = (__client_arr_t *)malloc(sizeof(__client_arr_t));
    if (!__clients_arr)
        return (84);
    memset(__clients_arr, 0, sizeof(__client_arr_t));
    __clients_arr->__clients = NULL;
    return (0);
}

static int construct_map(void)
{
    __map = (__map_t *)malloc(sizeof(__map_t));
    if (!__map)
        return (84);
    memset(__map, 0, sizeof(__map_t));
    __map->__cells = NULL;
    return (0);
}

int constructor(void)
{
    return (construct_args() != 0 ||
        construct_server() != 0 ||
        construct_clients() != 0 ||
        construct_map()) ? 84 : 0;
}