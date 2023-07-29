/*
** EPITECH PROJECT, 2022
** u_printf
** File description:
** print unsigned number
*/

#include"../Include/my_printf.h"

int u_printf(int nb)
{
    if (nb < 0){
        int reste = -nb % 10;
        if (reste > 6){
            my_put_nbr(429496729 + nb / 10 - 1);
            my_put_nbr(16 - reste);
        } else {
            my_put_nbr(429496729 + nb / 10);
            my_put_nbr(6 - reste);
        }
    } else
        my_put_nbr(nb);
    return 0;
}

int x_printf(int nb)
{
    int temp = nb;
    char a[80];
    for (int i = 0; temp > 0; i++){
        int reste = temp % 16;
        if (reste > 9){
            reste += 87;
            a[i] = reste;
        } else {
            a[i] = reste + '0';
        }
        temp = temp / 16;
    }
    if (nb == 0)
        my_put_nbr(0);
    my_revstr(a);
    my_putstr(a);
    return 0;
}

int grand_x_printf(int nb)
{
    int temp = nb;
    char a[80];
    for (int i = 0; temp > 0; i++){
        int reste = temp % 16;
        if (reste > 9){
            reste += 55;
            a[i] = reste;
        } else {
            a[i] = reste + '0';
        }
        temp = temp / 16;
    }
    if (nb == 0)
        my_put_nbr(0);
    my_revstr(a);
    my_putstr(a);
    return 0;
}

int p_printf(void *nb)
{
    unsigned long long temp = (unsigned long long) nb;
    char a[10000];
    for (int i = 0; temp > 0; i++){
        int reste = temp % 16;
        if (reste > 9){
            reste += 87;
            a[i] = reste;
        } else {
            a[i] = reste + '0';
        }
        temp = temp / 16;
    }
    if (nb == 0)
        my_put_nbr(0);
    my_revstr(a);
    my_putstr("0x");
    my_putstr(a);
    return 0;
}
