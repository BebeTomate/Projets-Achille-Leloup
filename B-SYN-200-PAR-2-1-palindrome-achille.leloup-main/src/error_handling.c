/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** error_handling
*/

#include <stdlib.h>
#include "proto.h"

static void init_param(struct palindrome *param)
{
    param->n = -1;
    param->p = -1;
    param->b = -1;
    param->imin = -1;
    param->imax = -1;
}

static int get_param2(char **av, struct palindrome *param, int i)
{
    if (strcmp(av[i], "-imin") == 0 && param->imin == -1) {
        param->imin = atoi(av[i + 1]);
        return 0;
    }
    if (strcmp(av[i], "-imax") == 0 && param->imax == -1) {
        param->imax = atoi(av[i + 1]);
        return 0;
    }
    return 1;
}

static int get_param(char **av, struct palindrome *param, int i)
{
    if (strcmp(av[i], "-n") == 0 && param->n == -1) {
        param->n = atoi(av[i + 1]);
        return 0;
    }
    if (strcmp(av[i], "-p") == 0 && param->p == -1) {
        param->p = atoi(av[i + 1]);
        return 0;
    }
    if (strcmp(av[i], "-b") == 0 && param->b == -1) {
        param->b = atoi(av[i + 1]);
        return 0;
    }
    if (get_param2(av, param, i) == 0)
        return 0;
    return 1;
}

static void update_param(struct palindrome *param)
{
    param->mode = 1;
    if (param->p != -1)
        param->mode = 2;
    if (param->b == -1)
        param->b = 10;
    if (param->imin == -1)
        param->imin = 0;
    if (param->imax == -1)
        param->imax = 100;
}

int error_handling(int ac, char **av, struct palindrome *param)
{
    int i = 1;

    init_param(param);
    if (ac < 3 || ac > 9 || (ac - 1) % 2 != 0)
        return 1;
    for (; i < ac; i++) {
        if (i % 2 == 0 && check_nb(av[i]) == 1)
            return 1;
        if (i % 2 != 0 && get_param(av, param, i) == 1)
            return 1;
    }
    if ((param->n == -1 && param->p == -1) ||
        (param->n != -1 && param->p != -1))
        return 1;
    update_param(param);
    if (param->imin > param->imax)
        return 1;
    if (param->b < 2 || param->b > 10)
        return 1;
    return 0;
}
