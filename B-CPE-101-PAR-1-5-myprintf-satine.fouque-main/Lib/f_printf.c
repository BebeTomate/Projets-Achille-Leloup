/*
** EPITECH PROJECT, 2022
** f printf
** File description:
** f printf
*/

#include"../Include/my_printf.h"

float if_f_printf(int t, float temp, int n, int entier)
{
    if ((t % 10) >= 5 && n != 0)
        temp += 1;
    if ((t % 10) >= 5 && n == 0)
        entier += 1;
    my_put_nbr(entier);
    return temp;
}

float if_e_f_printf(int t, float temp, int n, int entier)
{
    if ((t % 10) > 5 && n != 0)
        temp += 1;
    if ((t % 10) >= 5 && n == 0)
        entier += 1;
    my_put_nbr(entier);
    return temp;
}

float f_printf_bis(int n, float temp)
{
    if (n == -1){
        while (temp < 100000.0)
            temp = temp * 10;
    } else {
        for (int i = 0; i < n; i++)
            temp = temp * 10;
    }
    return temp;
}

void f_printf(float nb, int n, char f)
{
    int entier = nb, t, is_neg = 0;
    if (entier < 0){
        entier = -entier;
        nb = -nb;
        is_neg = 1;
    }
    float temp = nb - entier;
    if (temp != 0)
        temp = f_printf_bis(n, temp);
    if (n != -1)
        t = temp * 10;
    if (is_neg == 1)
        my_putchar('-');
    if (f == 'e')
        temp = if_e_f_printf(t, temp, n, entier);
    else
        temp = if_f_printf(t, temp, n, entier);
    display_f(n, temp);
}

int display_f(int n, float temp)
{
    if (n == -1 && temp == 0)
        my_putstr(".000000");
    if (n != 0 && temp != 0){
        my_putchar('.');
        my_put_nbr(temp);
    }
}
