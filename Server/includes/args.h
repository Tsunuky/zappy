/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef ARGS_H_
#define ARGS_H_

#include <stdint.h>
#include <stddef.h>

typedef struct __s_args
{
    int32_t __port;
    int32_t __width;
    int32_t __height;
    char **__names;
    int32_t __clients;
    int32_t __freq;
    int32_t __tunit;
} __args_t;

extern __args_t *__args;

char *concat_args(const char *const *const);
int check_help(const int, const char *const *const);
int check_args(const char *const *const);
int args_parser(const char *const *const);
int help(const char *const);

#endif