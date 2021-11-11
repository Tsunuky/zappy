/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/epoll.h>
#include <stdint.h>

typedef struct __s_client
{
    int32_t __cfd;
    char __input[4096];
    int32_t __input_length;
    char *__commands[10];
} __client_t;

typedef struct __s_client_arr
{
    __client_t **__clients;
    int32_t __size;
} __client_arr_t;

extern __client_arr_t *__clients_arr;

void *find_client(const int32_t);
int32_t commands_amount(__client_t *);
int command_shift(const int32_t, const char *const);
int add_client(const int32_t fd);
int remove_client(const int32_t fd);

#endif