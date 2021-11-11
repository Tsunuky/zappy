/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <sys/epoll.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "server.h"
#include "client.h"
#include "ctls.h"
#include "game.h"
#include "new.h"

static int event_loop(struct epoll_event **events, int *wt)
{
    int ni = 0;

    if (*wt < 0)
        return (84);
    else if (*wt > 0) {
        if ((*events)->data.fd == __server->__sfd)
            return (close_server() != 0 ? 84 : 1);
        else if (!find_client((*events)->data.fd)) {
            if (new_client() != 0)
                return (84);
        }
        else {
            ni = new_input(events);
            if (ni == 84)
                return (84);
            else if (ni == -1)
                client_ctl(CLIENT_CTL_DEL, (*events)->data.fd);
        }
    }
    return (0);
}

static int update_loop(struct epoll_event **events)
{
    int32_t amount = 0;
    char *res = NULL;

    //delta = last time - current time
    //max cast time = -1
    for (int32_t cpt = 0; cpt < __clients_arr->__size; cpt++) {
        amount = commands_amount(__clients_arr->__clients[cpt]);
        if (amount > 0) {
            input_ctl(COMMAND_CTL_POP, (*events)->data.fd, NULL, &res);
            dprintf(1, "after being removed ===> %s\n", res);
            parser((*events)->data.fd, res);

            //cast time -= delta
            //if cast time <= 0
                //execute a command
                //remove the command
                //parse next command
                //cast time = command time
                //if command ammount > 0 &&
                    //(max cast time == -1 || cast time < max cast time)
                    //max cast time = cast time
        }
        res = NULL;
    }
    return (0);
}

int loop(void)
{
    struct epoll_event *events = NULL;
    int wt = 0;
    int evl = 0;

    if (!(events = calloc(1, sizeof (struct epoll_event))))
        return (84);
    for (;;) {
        wt = epoll_wait(__server->__epfd, events, 1, -1);
        evl = event_loop(&events, &wt);
        if (evl == 1) {
            free(events);
            return (map_destroy() != 0 ? 84 : 0);
        }
        else if (evl != 0 && evl != 1)
            return (84);
        update_loop(&events);
    }
    return (0);
}