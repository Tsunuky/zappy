/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "args.h"

__map_t *__map = NULL;

int map_create(void)
{
    int32_t x = 0;
    int32_t y = 0;

    srand(time(NULL));
    __map->__width = __args->__width;
    __map->__height = __args->__height;
    __map->__size = __map->__width * __map->__height;
    if (!(__map->__cells = malloc((__map->__size + 1) * sizeof(__cell_t))))
        return (84);
    __map->__cells[__map->__size] = NULL;
    for (int32_t cpt = 0; cpt < __map->__size; cpt++) {
        if (!(__map->__cells[cpt] = malloc(sizeof(__cell_t))))
            return (84);
        __map->__cells[cpt]->__x = x;
        __map->__cells[cpt]->__y = y;
        if (!(__map->__cells[cpt]->__materials = malloc(sizeof(__materials_t))))
            return (84);
        __map->__cells[cpt]->__materials->__food = rand() % 10;
        __map->__cells[cpt]->__materials->__linemate = rand() % 10;
        __map->__cells[cpt]->__materials->__deraumere = rand() % 10;
        __map->__cells[cpt]->__materials->__sibur = rand() % 10;
        __map->__cells[cpt]->__materials->__mendiane = rand() % 10;
        __map->__cells[cpt]->__materials->__phiras = rand() % 10;
        __map->__cells[cpt]->__materials->__thystame = rand() % 10;
        x++;
        if (x == __map->__width) {
            y++;
            x = 0;
        }
    }
    return (0);
}

int map_destroy(void)
{
    for (int32_t cpt = 0; cpt < __map->__size; cpt++) {
        if (__map->__cells[cpt]) {
            if (__map->__cells[cpt]->__materials) {
                free(__map->__cells[cpt]->__materials);
                __map->__cells[cpt]->__materials = NULL;
            }
            free(__map->__cells[cpt]);
            __map->__cells[cpt] = NULL;
        }
    }
    return (0);
}