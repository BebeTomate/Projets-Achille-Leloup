/*
** EPITECH PROJECT, 2022
** S printf
** File description:
** S printf
*/

#include"../Include/my_printf.h"

int put_s_printf(char *str, int i)
{
    int j = 0;
    if (str[i] < 32){
        char a[80], temp = str[i];
        while (temp > 0){
            a[j++] = temp % 8 + '0';
            temp = temp / 8;
        }
        while (my_strlen(a) < 3)
            a[j++] = '0';
        a[j++] = '\\';
        my_revstr(a);
        my_putstr(a);
        j = 0;
    } else if (str[i] == 127)
        my_putstr("\\177");
    else
        my_putchar(str[i]);
    return 0;
}

int s_printf(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        put_s_printf(str, i);
    }
    return 0;
}

int o_printf(int nb)
{
    int temp = nb;
    char a[80];
    for (int i = 0; temp > 0; i++){
        int reste = temp % 8;
            a[i] = reste + '0';
        temp = temp / 8;
    }
    if (nb == 0)
        my_put_nbr(0);
    my_revstr(a);
    my_putstr(a);
    return 0;
}

int plus_flag_float(va_list ap, char l, const char *format, int i)
{
    float nb = va_arg(ap, double);
    if (l == 'e' || l == 'E' || l == 'f' || l == 'F' || l == 'g'
        || l == 'G'){
        if (nb > 0)
            my_putchar('+');
    }
    switch_cases_flags_bis(format, nb, l, i);
    return 0;
}

int plus_flag_int(va_list ap, char l, const char *format, int i)
{
    int nb = va_arg(ap, int);
    if (l == 'd' || l == 'i'){
        if (nb > 0)
            my_putchar('+');
    }
    switch_cases_flags(format, nb, l, i);
    return 0;
}
