/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverses a string
*/

#include"../Include/my_printf.h"

int my_strlen(char const *str)
{
    int compteur = 0;
    for (int i = 0; str[i] != '\0'; i++){
        compteur += 1;
    }
    return compteur;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    for (int j = 0; j < len; j++){
        char temp = str[len];
        str[len] = str[j];
        str[j] = temp;
        len--;
    }
    return str;
}

int count_digits_of_number(int nb)
{
    int comp = 1;
    int ten_exp = 10;
    while (nb > ten_exp){
        ten_exp = ten_exp * 10;
        comp += 1;
    }
    return comp;
}
