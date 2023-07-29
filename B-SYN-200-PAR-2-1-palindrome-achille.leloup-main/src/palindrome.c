/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

static void n_flag(struct palindrome *param)
{
    int i = 0;
    int result = param->n;
    int reverse = 0;
    int found = 0;

    for (; i <= param->imax; i++) {
        if (is_palindrome(result, param->b) == 1 && i >= param->imin) {
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            param->n, result, i, param->b);
            found = 1;
            break;
        }
        reverse = reverse_int(result, param->b);
        result += reverse;
    }
    if (found == 0)
        printf("no solution\n");
}

static int find_solutions(struct palindrome *param, int result, int i)
{
    int reverse = 0;
    int found = 0;
    int j = 0;

    for (; j <= param->imax; j++) {
        if (is_palindrome(result, param->b) == 1 &&
            result == param->p && j >= param->imin) {
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            i, param->p, j, param->b);
            found = 1;
            break;
        }
        reverse = reverse_int(result, param->b);
        result += reverse;
    }
    return found;
}

static void p_flag(struct palindrome *param)
{
    int i = 0;
    int result = 0;
    int found = 0;

    for (; i <= param->p; i++) {
        result = i;
        found += find_solutions(param, result, i);
    }
    if (found == 0)
        printf("no solution\n");
}

int palindrome(struct palindrome *param)
{
    if (param->mode == 1) {
        n_flag(param);
        return 0;
    }
    if (param->mode == 2 && is_palindrome(param->p, param->b) == 1) {
        p_flag(param);
        return 0;
    }
    return 1;
}
