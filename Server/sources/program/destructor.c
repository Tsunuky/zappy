/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <malloc.h>
#include <string.h>
#include <stddef.h>
#include "client.h"
#include "server.h"
#include "game.h"
#include "args.h"

static int destruct_args(void)
{
    if (!__args)
        return (0);
    if (__args->__names) {
        for (unsigned cpt = 0; __args->__names[cpt]; cpt++)
            free(__args->__names[cpt]);
        free(__args->__names);
        __args->__names = NULL;
    }
    free(__args);
    __args = NULL;
    return (0);
}

static int destruct_server(void)
{
    if (__server) {
        if (__server->__server) {
        free(__server->__server);
        __server->__server = NULL;
        }
        free(__server);
        __server = NULL;
    }
    return (0);
}

static int destruct_clients(void)
{
    if (__clients_arr) {
        if (__clients_arr->__clients) {
            free(__clients_arr->__clients);
            __clients_arr->__clients = NULL;
        }
        free(__clients_arr);
        __clients_arr = NULL;
    }
    return (0);
}

static int destruct_map(void)
{
    if (__map) {
        if (__map->__cells) {
            free(__map->__cells);
            __map->__cells = NULL;
        }
        free(__map);
        __map = NULL;
    }
    return (0);
}

int destructor(void)
{
    return (destruct_args() != 0 ||
        destruct_server() != 0 ||
        destruct_clients() != 0 ||
        destruct_map()) ? 84 : 0;
}