/*
** EPITECH PROJECT, 2022
** switch cases
** File description:
** switch cases
*/

#include"../Include/my_printf.h"

int switch_cases(const char *format, va_list ap, char letter, int i)
{
    char l = format[i];
    switch (l) {
    case 'd' : my_put_nbr(va_arg(ap, int)); break;
    case 'c' : my_putchar(va_arg(ap, int)); break;
    case 's' : my_putstr(va_arg(ap, char*)); break;
    case 'i' : my_put_nbr(va_arg(ap, int)); break;
    case '%' : my_putchar('%'); break;
    case 'b' : b_printf(va_arg(ap, int)); break;
    case 'u' : u_printf(va_arg(ap, int)); break;
    case 'x' : x_printf(va_arg(ap, int)); break;
    case 'X' : grand_x_printf(va_arg(ap, int)); break;
    case 'o' : o_printf(va_arg(ap, int)); break;
    case 'S' : s_printf(va_arg(ap, char*)); break;
    case 'f' :
    case 'F' : f_printf(va_arg(ap, double), -1, 'f'); break;
    case 'p' : p_printf(va_arg(ap, void*)); break;
    default: switch_cases_bis(format, ap, letter, i);
    }
    return 0;
}

int switch_cases_bis(const char *format, va_list ap, char letter, int i)
{
    char l = format[i];
    int c;
    float number;
    switch (l){
    case 'E' :
    case 'e' :
        number = va_arg(ap, double);
        c = e_printf(number, -1);
        if (number > 1 || number == 0.0)
            e_exp(letter, c, 0);
        else
            e_exp(letter, c, 1);
        break;
    default: switch_cases3(format, ap, letter, i);
    }
    return 0;
}

int switch_cases3(const char *format, va_list ap, char letter, int i)
{
    char l = format[i];
    switch (l){
    case 'G' :
    case 'g' : g_printf(va_arg(ap, double), -1, letter); break;
    case '#' : diese_flag(ap, letter, format, i + 1); break;
    case 39 :  quote_flag(ap, letter, format, i + 1); break;
    case '.' : point_flag(ap, letter, format, i + 1); break;
    case '0' : zero_flag(ap, letter, format, i + 1); break;
    case '+' :
        if (letter == 'd' || letter == 'i')
            plus_flag_int(ap, letter, format, i + 1);
        if (letter == 'e' || letter == 'E' || letter == 'f' || letter == 'F')
            plus_flag_float(ap, letter, format, i + 1);
        break;
    case '-' : minus_flag(ap, letter, format, i + 1); break;
    }
    if (l > 48 && l <= 57){
        blank_flag(ap, letter, format, i);
    }
}
