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

int     isSurrounded(t_main *main, unsigned int x, unsigned int y)
{
    if ((x > 0 && y > 0)
        && (main->map.table[x - 1][y - 1] == ' ' || main->map.table[x - 1][y - 1] == '\0' ||
        main->map.table[x - 1][y] == ' ' || main->map.table[x - 1][y] == '\0' ||
        main->map.table[x - 1][y + 1] == ' ' || main->map.table[x - 1][y + 1] == '\0' ||
        main->map.table[x][y - 1] == ' ' || main->map.table[x][y - 1] == '\0' ||
        main->map.table[x][y + 1] == ' ' || main->map.table[x][y + 1] == '\0' ||
        main->map.table[x + 1][y - 1] == ' ' || main->map.table[x + 1][y - 1] == '\0' ||
        main->map.table[x + 1][y] == ' ' || main->map.table[x + 1][y] == '\0' ||
        main->map.table[x + 1][y + 1] == ' ' || main->map.table[x + 1][y + 1] == '\0'))
        printf("ROOOOTOOO en: [%d][%d]\n", x, y);
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
        while (main->map.table[i][j])
        {
            if (ft_isdigit(main->map.table[i][j]) && i == 0 && main->map.table[i][j] != '1')
                printf("roto en: [%d][%d]\n", i, j);
            else if (ft_isdigit(main->map.table[i][j]) && i != main->map.rows)
                isSurrounded(main, i, j);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
