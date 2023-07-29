/*
** EPITECH PROJECT, 2023
** put nbr
** File description:
** put nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 0 && nb >= 10) {
        modulo = nb % 10;
        nb = (nb - modulo) / 10;
        my_put_nbr(nb);
        my_putchar(modulo + 48);
    } else {
        my_putchar(48 + nb % 10);
    }
    return 0;
}
