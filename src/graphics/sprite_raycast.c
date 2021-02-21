/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapconfigValidator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:33:07 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/28 19:33:10 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sprite_calculate(t_main *main)
{
    main->draw.sprite.height = abs((int)(main->win.height /
                                        main->draw.sprite.transform.y));
    main->draw.sprite.start.y = (main->win.height / 2) -
                               (main->draw.sprite.height / 2);
    if (main->draw.sprite.start.y < 0)
        main->draw.sprite.start.y = 0;
    main->draw.sprite.end.y = main->draw.sprite.start.y + main->draw.sprite.height;
    if (main->draw.sprite.end.y >= main->win.height)
        main->draw.sprite.end.y = main->win.height;
    main->draw.sprite.width = abs((int)(main->win.height /
                                       main->draw.sprite.transform.y));
    main->draw.sprite.start.x = main->draw.sprite.win -
                               (main->draw.sprite.width / 2);
    if (main->draw.sprite.start.x < 0)
        main->draw.sprite.start.x = 0;
    main->draw.sprite.end.x = main->draw.sprite.width / 2 + main->draw.sprite.win;
    if (main->draw.sprite.end.x >= main->win.width)
        main->draw.sprite.end.x = main->win.width;
}

static void	sprite_translate_to_camera(t_main *main, int i)
{
    main->draw.sprite.x = main->sprite[main->sprite_order[i]].x - main->pos.x;
    main->draw.sprite.y = main->sprite[main->sprite_order[i]].y - main->pos.y;
    main->draw.sprite.inver = 1.0 /
                             (main->plane.x * main->dir.y - main->dir.x * main->plane.y);
    main->draw.sprite.transform.x = main->draw.sprite.inver *
                                   (main->dir.y * main->draw.sprite.x
                                    - main->dir.x * main->draw.sprite.y);
    main->draw.sprite.transform.y = main->draw.sprite.inver *
                                   (-main->plane.y * main->draw.sprite.x
                                    + main->plane.x * main->draw.sprite.y);
    main->draw.sprite.win = (int)((main->win.width / 2) *
                                 (1 + main->draw.sprite.transform.x / main->draw.sprite.transform.y));
}

static void	sprite_projection(t_main *main)
{
    int	i;

    i = 0;
    while (i < main->sprite_count)
    {
        sprite_translate_to_camera(main, i);
        sprite_calculate(main);
        sprite_draw(main);
        i++;
    }
}

static void	sprite_sort(int *order, double *dist, int count)
{
    double	dist_tmp;
    int		order_tmp;
    int		sprite;
    int		i;

    i = 0;
    while (i < count - 1)
    {
        sprite = 0;
        while (sprite < count - 1)
        {
            if (dist[sprite] < dist[sprite + 1])
            {
                dist_tmp = dist[sprite + 1];
                dist[sprite + 1] = dist[sprite];
                dist[sprite] = dist_tmp;
                order_tmp = order[sprite + 1];
                order[sprite + 1] = order[sprite];
                order[sprite] = order_tmp;
            }
            sprite++;
        }
        i++;
    }
}

void		sprite_raycast(t_main *main)
{
    int		i;

    i = 0;
    while (i < main->sprite_count)
    {
        main->sprite_order[i] = i;
        main->sprite_dist[i] = pow(main->pos.x - main->sprite[i].x, 2)
                              + pow(main->pos.y - main->sprite[i].y, 2);
        i++;
    }
    sprite_sort(main->sprite_order, main->sprite_dist, main->sprite_count);
    sprite_projection(main);
}
