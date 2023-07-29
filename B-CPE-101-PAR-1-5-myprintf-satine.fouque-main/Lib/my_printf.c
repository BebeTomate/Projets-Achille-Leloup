/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf
*/

#include"../Include/my_printf.h"

int condition_letter(char l)
{
    if (l == 'o' || l == 'd' || l == 'c' || l == 's' || l == 'i'
        || l == '%' || l == 'b' || l == 'u' || l == 'x' || l == 'X'
        || l == 'S' || l == 'f' || l == 'e' || l == 'E' || l == 'F'
        || l == 'n' || l == 'p' || l == 'g' || l == 'G')
        return 1;
    else if (l == '#' || l == '.' || l >= '0' && l <= '9'
        || l == '+' || l == '0' || l == '-' || l == 39)
        return 0;
    else
        return -1;
}

int found_letter(const char *format, int i)
{
    int letter = i;
    while (condition_letter(format[letter]) == 0 || (format[letter] == 39
            && format[letter + 1] == 32 && format[letter + 2] == 39) ){
        if (format[letter] == 39 && format[letter + 1] == 32
            && format[letter + 2] == 39)
            letter += 3;
        else
            letter++;
    }
    if (condition_letter(format[letter]) == -1)
        return -1;
    return letter;
}

int compteur(const char *format, int i, int comp)
{
    int letter = found_letter(format, i + 1);
    if (format[i + 1] == 0 || format[i + 1] == '-')
        comp += format[i + 2] - 48;
    return comp;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int i = 0, letter, comp = 0;
    while (i < my_strlen(format)){
        if (format[i] == '%' && found_letter(format, i + 1) != -1) {
            letter = found_letter(format, i + 1);
            comp = compteur(format, i, comp);
            n_flag(format[letter], ap, comp);
            switch_cases(format, ap, format[letter], i + 1);
            i = letter;
        } else{
            my_putchar(format[i]);
            comp++;
        }
        i++;
    }
    va_end(ap);
    return 0;
}
