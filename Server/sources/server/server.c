/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <sys/signalfd.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <signal.h>
#include <malloc.h>
#include <string.h>
#include "server.h"
#include "client.h"
#include "ctls.h"
#include "args.h"

__server_t *__server = NULL;

int close_server(void)
{
    if (__server->__server) {
        free(__server->__server);
        __server->__server = NULL;
    }
    close(__server->__fd);
    if (__clients_arr->__clients) {
        for (int32_t cpt = 0; cpt < __clients_arr->__size; cpt++)
            if (!__clients_arr->__clients[cpt])
                continue ;
            else
                client_ctl(CLIENT_CTL_DEL,
                    __clients_arr->__clients[cpt]->__cfd);
    }
    close(__server->__sfd);
    close(__server->__epfd);
    return (0);
}

static int epolls(void)
{
    struct epoll_event event;
    sigset_t mask;

    memset(&event, 0, sizeof event);
    if ((__server->__epfd = epoll_create1(0)) == -1)
        return (84);
    event.data.fd = __server->__fd;
    event.events = EPOLLIN;
    if (epoll_ctl(__server->__epfd, EPOLL_CTL_ADD,
        __server->__fd, &event) == -1 || sigemptyset(&mask) != 0 ||
        sigaddset(&mask, SIGINT) != 0 || sigaddset(&mask, SIGQUIT) != 0 ||
        sigprocmask(SIG_BLOCK, &mask, NULL) != 0)
        return (84);
    if ((__server->__sfd = signalfd(-1, &mask, 0)) == -1)
        return (84);
    event.data.fd = __server->__sfd;
    if (epoll_ctl(__server->__epfd, EPOLL_CTL_ADD,
        __server->__sfd, &event) == -1)
        return (84);
    return (0);
}

int server(void)
{
    __server->__port = __args->__port;
    if (!(__server->__server = (struct sockaddr_in *)
        malloc(sizeof(struct sockaddr_in))))
        return (84);
    memset(__server->__server, 0, sizeof(struct sockaddr_in));
    __server->__server->sin_family = AF_INET;
    __server->__server->sin_port = htons(__server->__port);
    __server->__server->sin_addr.s_addr = htonl(INADDR_ANY);
    if ((__server->__fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        return (84);
    if (bind(__server->__fd, (struct sockaddr *)__server->__server,
        sizeof(struct sockaddr)) == -1 || listen(__server->__fd, 50) == -1)
        return (84);
    return epolls();
}
