/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/4 19:33:07 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/02/4 19:33:10 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     isSurrounded(t_main *main, unsigned int y, unsigned int x,
                     int quadrantType)
{
    printf("[%d][%d]\n", y, x);
    if (quadrantType == 1
        && (main->map.table[y - 1][x - 1] == ' '
        || main->map.table[y - 1][x - 1] == '\0'
        || main->map.table[y][x - 1] == ' '
        || main->map.table[y][x - 1] == '\0'
        || main->map.table[y + 1][x - 1] == ' '
        || main->map.table[y + 1][x - 1] == '\0'))
            error(E_MAP);
    if (main->map.table[y + 1][x] == ' '
        || main->map.table[y + 1][x] == '\0'
        || main->map.table[y + 1][x + 1] == ' '
        || main->map.table[y + 1][x + 1] == '\0'
        || main->map.table[y - 1][x] == ' '
        || main->map.table[y - 1][x] == '\0'
        || main->map.table[y - 1][x + 1] == ' '
        || main->map.table[y - 1][x + 1] == '\0'
        || main->map.table[y][x + 1] == ' '
        || main->map.table[y][x + 1] == '\0')
            error(E_MAP);
    return 1;
}

int     checkHorizontalQuadrant(t_main *main, unsigned int y, unsigned int x)
{
    if (main->map.table[y][x + 3] != ' '
            && main->map.table[y][x + 3] != '\0'
            && main->map.table[y][x + 3] != '1') {
        isSurrounded(main, y, x, 1);
        return 3;
    } else if (main->map.table[y][x + 2] != ' '
            && main->map.table[y][x + 2] != '\0'
            && main->map.table[y][x + 2] != '1') {
        isSurrounded(main, y, x, 2);
        return 2;
    }
    isSurrounded(main, y, x, 1);
    return 1;
}

int     checkVerticalQuadrant(t_main *main, unsigned int y, unsigned int x)
{
    if (main->map.table[y + 3][x] != ' ' && main->map.table[y + 3][x] != '\0')
        return 3;
    if (main->map.table[y + 2][x] != ' ' && main->map.table[y + 2][x] != '\0')
        return 2;
    return 1;
}

int     validateMap(t_main *main)
{
    unsigned int     i;
    unsigned int     j;

    i = 0;
    while (i < main->map.rows)
    {
        j = 0;
        while (j < ft_strlen(main->map.table[i]))
        {
            if (i == 0 && !(main->map.table[i][j] == ' ' || main->map.table[i][j] == '1'))
                error(E_MAP);
            if (main->map.table[i][j] != ' ' && main->map.table[i][j] != '1')
                j += checkHorizontalQuadrant(main, i, j);
            else
                j++;
        }
        printf("Fin de linea\n");
        i++;
    }
    return 0;
}