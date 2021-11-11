/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef NEW_H_
#define NEW_H_

#include <sys/epoll.h>

int new_client(void);
int new_input(struct epoll_event **);

#endif