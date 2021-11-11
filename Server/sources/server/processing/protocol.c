/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stddef.h>
#include "protocol.h"

const __protocol_t __protocol_tbl[] = {
    {"(msz)", 1, PROTO_NONE, &__proto_msz},
    {"(bct) ([0-9]+) ([0-9]+)", 3, PROTO_PARAM, &__proto_bct},
    {"(mct)", 1, PROTO_NONE, &__proto_mct},
    {"(tna)", 1, PROTO_NONE, &__proto_tna},
    {"(ppo) #([0-9]+)", 2, PROTO_PARAM, &__proto_ppo},
    {"(plv) #([0-9]+)", 2, PROTO_PARAM, &__proto_plv},
    {"(pin) #([0-9]+)", 2, PROTO_PARAM, &__proto_pin},
    {"(sgt)", 1, PROTO_NONE, &__proto_sgt},
    {"(sst) ([0-9]+)", 2, PROTO_PARAM, &__proto_sst},
    {NULL, -1, -1, NULL}
};