/*
** EPITECH PROJECT, 2023
** main
** File description:
** main palindrome
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int main(int ac, char **av)
{
    struct palindrome *param;

    param = malloc(sizeof(struct palindrome));
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    if (error_handling(ac, av, param) == 1) {
        printf("invalid argument\n");
        return 84;
    }
    if (palindrome(param) == 1) {
        printf("invalid argument\n");
        return 84;
    }
    free(param);
    return 0;
}
