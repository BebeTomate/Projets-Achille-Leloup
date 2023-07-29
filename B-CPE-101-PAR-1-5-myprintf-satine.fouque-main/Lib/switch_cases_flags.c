/*
** EPITECH PROJECT, 2022
** switch cases flags
** File description:
** switch cases flags
*/

#include"../Include/my_printf.h"

int switch_cases_flags(const char *format, int nb, char letter, int i)
{
    switch (letter) {
    case 'd' : my_put_nbr(nb); break;
    case 'i' : my_put_nbr(nb); break;
    }
    return 0;
}

int switch_cases_flags_bis(const char *format, float nb, char letter, int i)
{
    char l = format[i];
    int c;
    if (l == '.')
        point_flag_plus(nb, letter, format, i + 1);
    else {
        switch (letter){
        case 'E' :
        case 'e' :
            c = e_printf(nb, -1);
            if (nb > 1)
                e_exp(letter, c, 0);
            else
                e_exp(letter, c, 1);
            break;
        case 'G' :
        case 'g' : g_printf(nb, -1, letter); break;
        case 'f' :
        case 'F' : f_printf(nb, -1, 'f'); break;
        }
    }
}

int point_flag_plus(float nb, char letter, const char *format, int i)
{
    float number;
    int c;
    switch (letter){
    case 'F' :
    case 'f' : f_printf(nb, my_getnbr(format, i), 'f'); break;
    case 'E' :
    case 'e' :
        c = e_printf(nb, my_getnbr(format, i));
        if (nb > 1)
            e_exp(letter, c, 0);
        else
            e_exp(letter, c, 1);
        break;
    case 'g' :
    case 'G' :
        g_printf(nb, my_getnbr(format, i), letter); break;
    }
    return 0;
}
