/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct __s_materials
{
    int32_t __food;
    int32_t __linemate;
    int32_t __deraumere;
    int32_t __sibur;
    int32_t __mendiane;
    int32_t __phiras;
    int32_t __thystame;
} __materials_t;

typedef struct __s_cell
{
    uint32_t __x;
    uint32_t __y;
    __materials_t *__materials;
} __cell_t;

typedef struct __s_map
{
    int32_t __width;
    int32_t __height;
    __cell_t **__cells;
    int32_t __size;
} __map_t;

typedef struct __s_team
{
    const char *__name;
    int32_t __max;
    int32_t __remaining;
} __team_t;

typedef struct __s_team_arr
{
    __team_t **__teams;
    int32_t __size;
} __team_arr_t;

typedef struct __s_player
{
    uint32_t __id;
    uint32_t __x;
    uint32_t __y;
    __materials_t *__inventory;
    char *__team;
    char *__message;
    //orientation
    uint32_t __orientation;
    uint32_t __level;
    //hatching time
    bool __incantation;
} __player_t;

typedef struct __s_player_arr
{
    __player_t **__players;
    int32_t __size;
} __player_arr_t;

typedef struct __s_graphicclt
{
    __team_t *__team;
    int32_t __gcfd;
} __graphicclt_t;

extern __map_t *__map;
extern __player_arr_t *__player_arr;
extern __team_arr_t *__team_arr;
extern __graphicclt_t *__graphicclt;

int map_create(void);
int map_destroy(void);
int welcome(const int32_t);

//put player inside client
//elevation diagram

#endif