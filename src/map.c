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

int     isSurrounded(t_main *main, unsigned int y, unsigned int x)
{
    if ((x > 1 && y > 0) &&
        (main->map.table[y - 1][x - 1] == ' ' || main->map.table[y - 1][x - 1] == '\0' ||
        main->map.table[y - 1][x] == ' ' || main->map.table[y - 1][x] == '\0' ||
        main->map.table[y - 1][x + 1] == ' ' || main->map.table[y - 1][x + 1] == '\0' ||
        main->map.table[y][x - 1] == ' ' || main->map.table[y][x - 1] == '\0' ||
        main->map.table[y][x + 1] == ' ' || main->map.table[y][x + 1] == '\0' ||
        main->map.table[y + 1][x - 1] == ' ' || main->map.table[y + 1][x - 1] == '\0' ||
        main->map.table[y + 1][x] == ' ' || main->map.table[y + 1][x] == '\0' ||
        main->map.table[y + 1][x + 1] == ' ' || main->map.table[y + 1][x + 1] == '\0'))
    {
        printf("Mapa mal en [%d][%d]: %c", y, x, main->map.table[y][x]);
        return EXIT_FAILURE;
    }
//    printf("%c", main->map.table[y][x]);
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
            if ((i > 1 && j > 0) && main->map.table[i][j] != ' ' && main->map.table[i][j] != '1')
            isSurrounded(main, i, j);
//            if (ft_isdigit(main->map.table[i][j]) && i == 0 && main->map.table[i][j] != '1')
//                printf("roto en: [%d][%d]\n", i, j);
//            else if (ft_isdigit(main->map.table[i][j]) && i != main->map.rows)

            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}