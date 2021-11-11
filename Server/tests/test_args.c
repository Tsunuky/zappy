/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "program.h"
#include "args.h"

Test(__args, __args_1)
{
    const int ac = 2;
    const char *av[] = {"zappy_server", "-help"};
    cr_assert(check_help(ac, av) == 0);
}

Test(__args, __args_2)
{
    const int ac = 2;
    const char *av[] = {"zappy_server", "-bruh"};
    cr_assert(check_help(ac, av) != 0);
}

Test(__args, __args_3)
{
    cr_redirect_stdout();
    cr_assert(help("zappy_server") == 0);
}

Test(__args, __args_4)
{
    const char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "horse", "unicorn", "-c", "5", "-f", "100"};
    cr_assert(check_args(av) == 0);
}

Test(__args, __args_5)
{
    const char *av[] = {"./zappy_server", "-p", "12345", "-x", "1000", "-y",
        "1000", "-n", "red", "blue", "orange", "yellow", "green", "-c", "15",
        "-f", "360"};
    cr_assert(check_args(av) == 0);
}

Test(__args, __args_6)
{
    const char *av[] = {"./zappy_server", "-p", "port", "-x", "x", "-y", "y",
        "-n", "n", "n", "-c", "c", "-f", "f"};
    cr_assert(check_args(av) != 0);
}

Test(__args, __args_7)
{
    const char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "horse", "unicorn", "-c", "5", "-f", "100"};
    constructor();
    cr_assert(args_parser(av) == 0);
    destructor();
}

Test(__args, __args_8)
{
    const char *av[] = {"./zappy_server", "-p", "12345", "-x", "1000", "-y",
        "1000", "-n", "red", "blue", "orange", "yellow", "green", "-c", "15",
        "-f", "360"};
    constructor();
    cr_assert(args_parser(av) == 0);
    destructor();
}
