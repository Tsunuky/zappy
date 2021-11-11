/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <criterion/criterion.h>
#include "program.h"

Test(__constructor, __constructor_1)
{
    cr_assert(constructor() == 0);
}

Test(__constructor, __constructor_2)
{
}

Test(__destructor, __destructor_1)
{
    cr_assert(destructor() == 0);
}

Test(__destructor, __destructor_2)
{
}