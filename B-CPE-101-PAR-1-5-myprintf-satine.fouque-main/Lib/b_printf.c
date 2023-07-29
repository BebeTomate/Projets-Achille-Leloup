/*
** EPITECH PROJECT, 2022
** bprint
** File description:
** printf
*/

#include"../Include/my_printf.h"

int b_printf(int nb)
{
    char buffer[256], temp;
    int display;
    if (nb < 0)
        return (84);
    for (display = 0; nb != 0; display++) {
        if (nb % 2 == 0)
            buffer[display] = '0';
        else
            buffer[display] = '1';
        nb = nb / 2;
    }
    buffer[display] = '\0';
    int mid = display / 2, midend = display - 1;
    for (int i = 0; i < mid; i++) {
        temp = buffer[i];
        buffer[i] = buffer[midend - i];
        buffer[midend - i] = temp;
    }
    my_putstr(buffer);
    return 0;
}

int quote_flag(va_list ap, char l, const char *format, int i)
{
    if (l == 'd' || l == 'i' || l == 'f' || l == 'F'
        || l == 'e' || l == 'E' || l == 'g' || l == 'G')
        my_putchar(' ');
    switch_cases(format, ap, l, i + 2);
}

int minus_flag(va_list ap, char letter, const char *format, int i)
{
    if (letter == 'd' || letter == 'i' || letter == 'c')
        minus_int(ap, letter, format, i);
    if (letter == 's')
        minus_str(ap, letter, format, i);
}

int minus_int(va_list ap, char l, const char *format, int i)
{
    int nb = va_arg(ap, int), comp = 1, j = 0;
    if (l != 'c'){
        comp = count_digits_of_number(nb);
        if (nb < 0){
            my_putchar('-');
            nb = -nb;
            comp += 1;
        }
    }
    if (format[i] >= 48 && format[i] <= 57){
        int number = my_getnbr(format, i);
        if (number < 0)
            number = -number;
        if (number > comp)
            j = number - comp;
    }
    (l == 'c') ? my_putchar(nb) : switch_cases_flags(format, nb, l, i);
    for (int k = 0; k < j; k++)
        my_putchar(' ');
}

int minus_str(va_list ap, char letter, const char *format, int i)
{
    char *str = va_arg(ap, char *);
    int comp = my_strlen(str), j = 0;
    if (format[i] >= 48 && format[i] <= 57){
        int number = my_getnbr(format, i);
        if (number < 0)
            number = -number;
        if (number > comp)
            j = number - comp;
    }
    my_putstr(str);
    for (int k = 0; k < j; k++)
        my_putchar(' ');
}
