/*
** EPITECH PROJECT, 2023
** utils
** File description:
** lib
*/

#include <stdio.h>
#include "struct.h"

void usage(void)
{
    printf("USAGE\n      ./palindrome -n number -p palindrome"
    " [-b base] [-imin i] [-imax i]\n\nDESCRIPTION\n"
    "      -n n\tinteger to be transformed (>=0)\n      "
    "-p p\tpalindromic number to be obtained "
    "(incompatible with the -n option) (>=0)\n\t\t"
    "if defined, all fitting values of n will be output\n"
    "      -b base\tbase in which the procedure will be executed"
    " (1<b<=10) [def: 10]\n      -imin i\tminimum number of "
    "iterations, included (>=0) [def: 0]\n      -imax i\t"
    "maximum number of iterations, included (>=0) [def: 100]\n");
}

int check_nb(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

int reverse_int(int nb, int base)
{
    int rev_nb = 0;

    while (nb != 0) {
        rev_nb = rev_nb * base + nb % base;
        nb /= base;
    }
    return rev_nb;
}

int is_palindrome(int nb, int base)
{
    int reversed = 0;
    int original = nb;
    int digit = 0;

    while (nb != 0) {
        digit = nb % base;
        if (reversed > (2147483647 / base) ||
        (reversed == (2147483647 / base) && digit > 7))
            return 0;
        reversed = reversed * base + digit;
        nb /= base;
    }
    return original == reversed;
}
