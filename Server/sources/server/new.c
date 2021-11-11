/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <sys/epoll.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "server.h"
#include "client.h"
#include "game.h"
#include "ctls.h"

static size_t fbreak(char *str, size_t start, size_t end)
{
    for (size_t cpt = start; cpt < end; cpt++)
        if (str[cpt] == '\n')
            return cpt;
    return -1;
}

int new_client(void)
{
    struct sockaddr_in client_in;
    struct epoll_event event;
    int32_t len = 0;
    int nfd = 0;
    int wlc = 0;

    memset(&event, 0, sizeof event);
    if ((nfd = accept(__server->__fd, (struct sockaddr *)&client_in,
        (socklen_t *)&len)) < 0) {
        dprintf(fileno(stderr), "%s\n", strerror(errno));
        return (0);
    }
    if (client_ctl(CLIENT_CTL_ADD, nfd) != 0)
        return (84);
    event.events = EPOLLIN;
    event.data.fd = nfd;
    wlc = welcome(nfd);
    if (wlc == 84)
        return (84);
    else if (wlc == -1) {
        close(nfd);
        return (0);
    }
    if (epoll_ctl(__server->__epfd, EPOLL_CTL_ADD, nfd, &event) == -1) {
        dprintf(1, "error\n");
        return 84;
    }
    return 0;
}

int new_input(struct epoll_event **events)
{
    __client_t *client = NULL;
    char buffer[4096];
    ssize_t size = 0;
    size_t old_size = 0;

    memset(&buffer, 0, 4096);
    client = ((__client_t *)find_client((*events)->data.fd));
    old_size = client->__input_length;
    if ((size = read(client->__cfd, client->__input + client->__input_length,
        4096 - client->__input_length)) <= 0)
        return (client_ctl(CLIENT_CTL_DEL, (*events)->data.fd));
    client->__input_length += size;
    for (int32_t cpt = fbreak(client->__input, old_size,
        client->__input_length); cpt >= 0; cpt = fbreak(client->__input,
        old_size, client->__input_length)) {
        memcpy(buffer, client->__input, cpt + 1);
        client->__input_length -= cpt + 1;
        old_size = 0;
        memmove(client->__input, client->__input + cpt + 1,
            client->__input_length);
        buffer[cpt] = '\0';
        if (input_ctl(COMMAND_CTL_PUSH, (*events)->data.fd,
            buffer, NULL) != 0)
            return (84);
    }
    return (client->__input_length >= 4096) ? -1 : 0;
}