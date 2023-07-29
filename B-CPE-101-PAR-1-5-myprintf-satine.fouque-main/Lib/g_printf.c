/*
** EPITECH PROJECT, 2022
** gprintf
** File description:
** gprintf
*/

#include"../Include/my_printf.h"

int g_printf(float dec, int nb, char g)
{
    if (dec < 0){
        dec = -dec;
        my_putchar('-');
    }
    if (nb == -1)
        g_printf_default(dec, 6, g);
    else
        g_printf_default(dec, nb, g);
}

int g_printf_default(float dec, int nb, char g)
{
    int ent = dec;
    float rt = dec - ent;
    if (count_digits_of_number(ent) <= nb){
        while ((count_digits_of_number(ent) + count_digits_of_number(rt)) < nb
                && ((int) (rt * 10) % 10 != 0)){
            rt = rt * 10;
        }
        my_put_nbr(ent);
        if (count_digits_of_number(ent) != nb && rt != 0){
            my_putchar('.');
            my_put_nbr(rt);
        }
    } else {
        if (nb == 0)
            display_g(ent, g, nb);
        else
            display_g(ent, g, nb - 1);
    }
    return 0;
}

int display_g(int entier, char g, int nb)
{
    int c = e_printf(entier, nb);
    char e;
    if (g == 'g')
        e = 'e';
    else
        e = 'E';
    if (entier > 1)
        e_exp(e, c, 0);
    else
        e_exp(e, c, 1);
    return 0;
}
