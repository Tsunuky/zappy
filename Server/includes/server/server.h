/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/ip.h>
#include <stdint.h>
#include <stddef.h>

typedef struct __s_server
{
    int32_t __port;
    int32_t __fd;
    int32_t __epfd;
    int32_t __sfd;
    struct sockaddr_in *__server;
} __server_t;

extern __server_t *__server;

int loop(void);
int server(void);
int close_server(void);
int parser(const int32_t, const char *const);

#endif