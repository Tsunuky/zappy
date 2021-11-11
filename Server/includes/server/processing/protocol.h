/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdint.h>
#include <stdio.h>
#include "game.h"

typedef enum __s_protocol_params
{
    PROTO_NONE, PROTO_PARAM
} __protocol_params_t;

typedef struct __s_protocol
{
    const char *__expr;
    const uint32_t __groups;
    const __protocol_params_t __params;
    int(*__fcn)(const char *, const int32_t, __player_t *);
} __protocol_t;

extern const __protocol_t __protocol_tbl[];

int __proto_msz(const char *, const int32_t, __player_t *);
int __proto_bct(const char *, const int32_t, __player_t *);
int __proto_mct(const char *, const int32_t, __player_t *);
int __proto_tna(const char *, const int32_t, __player_t *);
int __proto_ppo(const char *, const int32_t, __player_t *);
int __proto_plv(const char *, const int32_t, __player_t *);
int __proto_pin(const char *, const int32_t, __player_t *);
int __proto_sgt(const char *, const int32_t, __player_t *);
int __proto_sst(const char *, const int32_t, __player_t *);

int __proto_pnw(const int32_t, __player_t *);
int __proto_pex(const int32_t, __player_t *);
int __proto_pbc(const int32_t, __player_t *);
int __proto_pic(const int32_t, __player_t *);
int __proto_pie(const int32_t, __player_t *);
int __proto_pfk(const int32_t, __player_t *);
int __proto_pdr(const int32_t, __player_t *, const int32_t);
int __proto_pgt(const int32_t, __player_t *, const int32_t);
int __proto_pdi(const int32_t, __player_t *);
int __proto_enw(const int32_t, __player_t *);
int __proto_eht(const int32_t, __player_t *);
int __proto_ebo(const int32_t, __player_t *);
int __proto_edi(const int32_t, __player_t *);
int __proto_seg(const int32_t, __player_t *);
int __proto_smg(const int32_t, __player_t *);
int __proto_suc(const int32_t, __player_t *);
int __proto_sbp(const int32_t, __player_t *);

// client commands
// msz\n -> msz X Y\n // map size
// bct X Y\n -> bct X Y Q0..Q6\n // content of a tile
// mct\n -> bct X Y Q0..Q6\n * tiles // bct on all tiles
// tna\n -> tna Name\n * teams // all teams names
// ppo #n\n -> ppo n X Y O\n // player position and orientation
// plv #n\n -> plv n L\n // player level
// pin #n\n -> pin n X Y Q0..Q6\n // inventory of player
// sgt\n -> sgt T\n // frequence / time unit
// sst T\n -> sst T\n // frequence edit / time unit edit

// server answers (debug ?)
// pnw #n X Y O L N\n // new player connection
// pex n\n // expulsion
// pbc n N\n // broascast
// pic X Y L n..n\n // incantation start (started by first n)
// pie X Y R\n // incantation ending
// pfk n\n // setting down an egg
// pdr n i\n // drop ressource (x1 of type i)
// pgt n i\n // get ressource (x1 of type i)
// pdr n\n // player's death
// enw e n X Y\n // egg has been laid
// eht e\n // egg hatching
// ebo e\n // player is connecting to an egg
// edi e\n // hatched egg's death
// seg N\n // end of game
// smg M\n // message from server
// suc\n // unknown cmd
// sbp\n // bad parameter

#endif
