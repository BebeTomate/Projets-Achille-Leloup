/*
** EPITECH PROJECT, 2022
** print exponent
** File description:
** print exponent
*/

#include"../Include/my_printf.h"

int e_pos(float nb, int n)
{
    int comp = 0;
    float temp = nb;
    while (temp > 10){
        temp = temp / 10;
        comp++;
    }
    f_printf(temp, n, 'e');
    return comp;
}

int e_exp(char e, int comp, int is_neg)
{
    if (e == 'e')
        write(1, "e", 1);
    if (e == 'E')
        write(1, "E", 1);
    if (is_neg == 1)
        my_putchar('-');
    else
        my_putchar('+');
    if (comp < 10)
        my_put_nbr(0);
    my_put_nbr(comp);
    return 0;
}

int e_neg(float nb, int n)
{
    int comp = 0;
    float temp = nb;
    while (temp < 1){
        temp = temp * 10;
        comp++;
    }
    f_printf(temp, n, 'e');
    return 0;
}

int e_printf(float nb, int n)
{
    int co;
    int is_neg = 0;
    if (nb < 0){
        is_neg = 1;
        nb = -nb;
    }
    if (nb > 1 && nb > 0){
        if (is_neg == 1)
            my_putchar('-');
        co = e_pos(nb, n);
    } else if (nb == 0.0){
        co = e_pos(nb, n);
    } else {
        if (is_neg == 1)
            my_putchar('-');
        co = e_neg(nb, n);
    }
    return co;
}
