/*
** EPITECH PROJECT, 2022
** flags
** File description:
** flags
*/

#include"../Include/my_printf.h"

int blank_flag(va_list ap, char letter, const char *format, int i)
{
    if (letter == 'd' || letter == 'i' || letter == 'c')
        blank_int(ap, letter, format, i);
    if (letter == 's')
        blank_str(ap, letter, format, i);
}

int blank_int(va_list ap, char letter, const char *format, int i)
{
    int nb = va_arg(ap, int), comp = 1, j = 0;
    if (letter != 'c'){
        comp = count_digits_of_number(nb);
        if (nb < 0){
            my_putchar('-');
            nb = -nb;
            comp += 1;
        }
    }
    if (format[i] >= 48 && format[i] <= 57){
        int number = my_getnbr(format, i);
        if (number > comp)
            j = number - comp;
    }
    for (int k = 0; k < j; k++)
        my_putchar(' ');
    if (letter == 'c')
        my_putchar(nb);
    else
        switch_cases_flags(format, nb, letter, i);
}

int blank_str(va_list ap, char letter, const char *format, int i)
{
    char *str = va_arg(ap, char *);
    int comp = my_strlen(str);
    int j = 0;
    if (format[i] >= 48 && format[i] <= 57){
        int number = my_getnbr(format, i);
        if (number < 0)
            number = -number;
        if (number > comp)
            j = number - comp;
    }
    for (int k = 0; k < j; k++)
        my_putchar(' ');
    my_putstr(str);
}

int zero_flag(va_list ap, char letter, const char *format, int i)
{
    if (letter == 'd' || letter == 'i' || letter == 'c')
        zero_int(ap, letter, format, i);
    if (letter == 's')
        blank_str(ap, letter, format, i);
}

int zero_int(va_list ap, char letter, const char *format, int i)
{
    int nb = va_arg(ap, int), comp = 1, j = 0;
    if (letter != 'c'){
        comp = count_digits_of_number(nb);
        if (nb < 0){
            my_putchar('-');
            nb = -nb;
            comp += 1;
        }
    }
    if (format[i] >= 48 && format[i] <= 57){
        int number = my_getnbr(format, i);
        if (number > comp)
            j = number - comp;
    }
    for (int k = 0; k < j; k++)
        my_putchar('0');
    if (letter == 'c')
        my_putchar(nb);
    else
        switch_cases_flags(format, nb, letter, i);
}
