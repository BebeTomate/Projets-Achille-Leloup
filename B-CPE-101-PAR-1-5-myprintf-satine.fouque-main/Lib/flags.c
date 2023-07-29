/*
** EPITECH PROJECT, 2022
** flags
** File description:
** flags
*/

#include"../Include/my_printf.h"

int diese_flag(va_list ap, char letter, const char *format, int i)
{
    switch (letter){
    case 'o' : my_putchar('0'); o_printf(va_arg(ap, int)); break;
    case 'F' :
    case 'f' :
        if (format[i] == '.' && format[i + 1] - 48 == 0){
            f_printf(va_arg(ap, double), format[i + 1] - 48, 'f');
            my_putchar('.');
        } else
            switch_cases(format, ap, letter, i);
        break;
    case 'x' : my_putstr("0x"); switch_cases(format, ap, letter, i); break;
    case 'X' : my_putstr("0X"); switch_cases(format, ap, letter, i); break;
    default: diese_flag_e(ap, letter, format, i);
    }
    return 0;
}

int diese_flag_e(va_list ap, char letter, const char *format, int i)
{
    float number;
    int c;
    switch (letter){
    case 'E' :
    case 'e' :
        if (format[i] == '.' && format[i + 1] - 48 == 0){
            number = va_arg(ap, double);
            c = e_printf(number, format[i + 1] - 48);
            my_putchar('.');
            if (number > 1)
                e_exp(letter, c, 0);
            else
                e_exp(letter, c,  1);
        } else
            switch_cases(format, ap, letter, i);
        break;
    default: diese_flag_g(ap, letter, format, i);
    }
    return 0;
}

int diese_flag_g(va_list ap, char letter, const char *format, int i)
{
    float number;
    int c;
    switch (letter){
    case 'g' :
    case 'G' :
        if (format[i] == '.' && format[i + 1] - 48 == 0){
            g_printf(va_arg(ap, double), 0, letter);
            my_putchar('.');
        } else
            switch_cases(format, ap, letter, i);
        break;
    }
    return 0;
}

int point_flag(va_list ap, char letter, const char *format, int i)
{
    float number;
    int c;
    switch (letter){
    case 'F' :
    case 'f' : f_printf(va_arg(ap, double), my_getnbr(format, i), 'f'); break;
    case 'E' :
    case 'e' :
        number = va_arg(ap, double);
        c = e_printf(number, my_getnbr(format, i));
        if (number > 1 || number == 0)
            e_exp(letter, c, 0);
        else
            e_exp(letter, c, 1);
        break;
    case 'g' :
    case 'G' :
        g_printf(va_arg(ap, double), my_getnbr(format, i), letter); break;
    }
    return 0;
}

int n_flag(char l, va_list ap, int comp)
{
    int *a = malloc(sizeof(int));
    if (l == 'n'){
        a = va_arg(ap, void*);
        *a = comp;
    }
    return 0;
}
