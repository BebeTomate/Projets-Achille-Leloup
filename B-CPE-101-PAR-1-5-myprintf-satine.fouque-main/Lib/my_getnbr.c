/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** return a number of a string
*/

#include"../Include/my_printf.h"

int nombre_moins(int nb, int moins)
{
    if (moins == 1){
        return nb * -1;
    }
    return nb;
}

int my_getnbr(char const *str, int j)
{
    int nombre;
    int i = j;
    int moins = 0;
    while ('0' > str[i] || str[i] > '9'){
        i++;
    }
    nombre = str[i] - 48;
    if (str[i - 1] == '-'){
        moins = 1;
    }
    i++;
    while ('0' <= str[i] && str[i] <= '9'){
        nombre = nombre * 10 + (str[i] - 48);
        if (nombre < 0 && nombre != -2147483648){
            return 0;
            }
        i++;
    }
    return nombre_moins(nombre, moins);
}
