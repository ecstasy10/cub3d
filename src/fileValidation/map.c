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

void    isSurrounded(t_main *main, unsigned int y, unsigned int x,
                     int quadrantType)
{
    char    *badMap;
//    char    *player;

    badMap = " " "\0";
//    player = "N" "S" "E" "W";
    if (quadrantType == 1
        && (!!ft_strchr(badMap, main->map.table[y - 1][x - 1])
        || !!ft_strchr(badMap, main->map.table[y][x - 1])
        || !!ft_strchr(badMap, main->map.table[y + 1][x - 1])))
            error(E_MAP);
    if (!!ft_strchr(badMap, main->map.table[y + 1][x])
        || !!ft_strchr(badMap, main->map.table[y + 1][x + 1])
        || !!ft_strchr(badMap, main->map.table[y - 1][x])
        || !!ft_strchr(badMap, main->map.table[y - 1][x + 1])
        || !!ft_strchr(badMap, main->map.table[y][x + 1]))
            error(E_MAP);
}

int     checkHorizontalQuadrant(t_main *main, unsigned int y, unsigned int x)
{
    if (main->map.table[y][(x + 2)] != ' '
            && main->map.table[y][(x + 2)] != '\0'
            && main->map.table[y][(x + 2)] != '1') {
        isSurrounded(main, y, x, 1);
        return (3);
    } else if (main->map.table[y][(x + 2)] != ' '
            && main->map.table[y][(x + 2)] != '\0'
            && main->map.table[y][(x + 2)] != '1') {
        isSurrounded(main, y, x, 2);
        return (2);
    } else {
        isSurrounded(main, y, x, 2);
        return (1);
    }
}

void     validation(t_main *main, unsigned int i, unsigned int j)
{
    if ((i == 0 || i == (main->map.rows - 1))
        && !(main->map.table[i][j] == ' ' || main->map.table[i][j] == '1'))
        error(E_MAP);
    else if (main->map.table[i][j] == '0')
        isSurrounded(main, i, j, 1);
    else if (main->map.table[i][j] == 'N' || main->map.table[i][j] == 'S'
        || main->map.table[i][j] == 'E' || main->map.table[i][j] == 'W')
        isPlayer(main, i, j);
    else if (main->map.table[i][j] == '2')
        sprite_control(main, i, j);
}

int     validateMap(t_main *main)
{
    unsigned int     i;
    unsigned int     j;

    main->map.spritesLength = 0;
    i = 0;
    while (i < main->map.rows)
    {
        j = 0;
        while (j < ft_strlen(main->map.table[i]))
        {
            validation(main, i, j);
            j++;
        }
        i++;
    }
    if (!main->player.x)
        error(E_NOT_PLAYER);
    return (0);
}