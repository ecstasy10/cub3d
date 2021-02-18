/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:04:58 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/02/11 20:04:59 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        spriteControl(t_main *main, int y, int x)
{
    main->sprite[main->map.spritesLength].x = (double)y + 0.5;
    main->sprite[main->map.spritesLength].y = (double)x + 0.5;
    main->map.spritesLength++;
}

void	    directionControl(t_main *main, double x, double y)
{
    main->dir.x = x;
    main->dir.y = y;
}

void	    planeControl(t_main *main, double x, double y)
{
    main->plane.x = x;
    main->plane.y = y;
}

void        isPlayer(t_main *main, unsigned int y, unsigned int x)
{
    if (main->player.x)
        error(E_PLAYER);
    main->player.x = (double)y + 0.5;
    main->player.y = (double)x + 0.5;
    if (main->map.table[y][x] == 'N')
    {
        directionControl(main, -1, 0);
        planeControl(main, 0, 0.66);
    }
    else if (main->map.table[y][x] == 'S')
    {
        directionControl(main, 1, 0);
        planeControl(main, 0, -0.66);
    }
    else if (main->map.table[y][x] == 'W')
    {
        directionControl(main, 0, -1);
        planeControl(main, -0.66, 0);
    }
    else if (main->map.table[y][x] == 'E')
    {
        directionControl(main, 0, 1);
        planeControl(main, 0.66, 0);
    }
}
