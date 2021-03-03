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

static void	vertical_calculate(t_main *main)
{
    main->draw.height = main->win.height / main->ray.wall.dist;
    main->draw.start = (main->win.height / 2) - (main->draw.height / 2);
    if (main->draw.start < 0)
        main->draw.start = 0;
    main->draw.end = main->draw.start + main->draw.height;
    if (main->draw.end >= main->win.height)
        main->draw.end = main->win.height - 1;
}

static void	wall_ray_distance_calculate(t_main *main)
{
    if (main->ray.wall.side == 0)
        main->ray.wall.dist = (main->maze.x - main->player.x +
                              (1 - main->ray.step.x) / 2) / main->ray.dir.x;
    else
        main->ray.wall.dist = (main->maze.y - main->player.y +
                              (1 - main->ray.step.y) / 2) / main->ray.dir.y;
}

static void	wall_ray_hit_calculate(t_main *main)
{
    main->ray.wall.hit = 0;
    while (main->ray.wall.hit == 0)
    {
        if (main->ray.side.dist.x < main->ray.side.dist.y)
        {
            main->ray.side.dist.x += main->ray.delta.x;
            main->maze.x += main->ray.step.x;
            main->ray.wall.side = 0;
        }
        else if (main->ray.side.dist.x > main->ray.side.dist.y)
        {
            main->ray.side.dist.y += main->ray.delta.y;
            main->maze.y += main->ray.step.y;
            main->ray.wall.side = 1;
        }
        if (main->map.table[main->maze.x][main->maze.y] == '1')
            main->ray.wall.hit = 1;
    }
}

static void	wall_ray_step_and_initial_side_calculate(t_main *main)
{
    if (main->ray.dir.x < 0)
    {
        main->ray.step.x = -1;
        main->ray.side.dist.x = (main->player.x - main->maze.x) * main->ray.delta.x;
    }
    else
    {
        main->ray.step.x = 1;
        main->ray.side.dist.x = (main->maze.x + 1.0 - main->player.x) *
        main->ray.delta.x;
    }
    if (main->ray.dir.y < 0)
    {
        main->ray.step.y = -1;
        main->ray.side.dist.y = (main->player.y - main->maze.y) * main->ray.delta.y;
    }
    else
    {
        main->ray.step.y = 1;
        main->ray.side.dist.y = (main->maze.y + 1.0 - main->player.y) *
        main->ray.delta.y;
    }
}

void		wall_raycast(t_main *main)
{
    int	tex;

    main->ray.x = 0;
    while (main->ray.x < main->win.width)
    {
        main->ray.cam.x = (2 * main->ray.x) / (double)main->win.width - 1;
        main->ray.dir.x = main->dir.x + main->plane.x * main->ray.cam.x;
        main->ray.dir.y = main->dir.y + main->plane.y * main->ray.cam.x;
        main->maze.x = (int)main->player.x;
        main->maze.y = (int)main->player.y;
        main->ray.delta.x = dist(main->ray.dir.y, main->ray.dir.x);
        main->ray.delta.y = dist(main->ray.dir.x, main->ray.dir.y);
        wall_ray_step_and_initial_side_calculate(main);
        wall_ray_hit_calculate(main);
        wall_ray_distance_calculate(main);
        main->draw.z_buffer[main->ray.x] = main->ray.wall.dist;
        vertical_calculate(main);
        tex = texture_sort(main);
        texture_calculate(main, tex);
        vertical_draw(main, main->ray.x, tex);
        main->ray.x++;
    }
}
