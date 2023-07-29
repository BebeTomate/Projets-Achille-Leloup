/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** requirement
*/

int my_factrec_synthesis(int nb)
{
    int last_fact = 0;

    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0 || nb == 1)
        return 1;
    last_fact = my_factrec_synthesis(nb - 1);
    if (last_fact == 0)
        return 0;
    else
        return nb * last_fact;
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;

    if (nb < 0 || nb > 46340 * 46340)
        return -1;
    for (; i <= 46340; ++i)
        if (i * i == nb)
            return i;
    return -1;
}
