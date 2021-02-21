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

int		texture_sort(t_main *main)
{
    int	tex;

    if (main->ray.wall.side == 1)
    {
        if (main->ray.dir.y > 0)
            tex = 2;
        else
            tex = 3;
    }
    else
    {
        if (main->ray.dir.x > 0)
            tex = 1;
        else
            tex = 0;
    }
    return (tex);
}

void	texture_calculate(t_main *main, int i)
{
    if (main->ray.wall.side == 0)
        main->ray.wall.x = main->pos.y + main->ray.wall.dist * main->ray.dir.y;
    else
        main->ray.wall.x = main->pos.x + main->ray.wall.dist * main->ray.dir.x;
    main->ray.wall.x -= floor(main->ray.wall.x);
    main->tex[i].x = (int)(main->ray.wall.x * (double)main->tex[i].width);
    if (main->ray.wall.side == 0 && main->ray.dir.x > 0)
        main->tex[i].x = main->tex[i].width - main->tex[i].x - 1;
    if (main->ray.wall.side == 1 && main->ray.dir.y < 0)
        main->tex[i].x = main->tex[i].width - main->tex[i].x - 1;
    main->tex[i].step = 1.0 * main->tex[i].height / main->draw.height;
    main->tex[i].pos = (main->draw.start - main->win.height / 2 +
                       main->draw.height / 2) * main->tex[i].step;
}

void	texture_initialize(t_main *main)
{
    int	i;

    i = 0;
    while (i < 5)
    {
        if (!(main->tex[i].img = mlx_xpm_file_to_image(main->mlx.ptr,
                main->tex[i].path, &main->tex[i].width,
                &main->tex[i].height)))
            error(E_TEX);
        if (!(main->tex[i].img->buff =
                (int*)mlx_get_data_addr(main->tex[i].img,
                &main->tex[i].img->bits_per_pixel,
                &main->tex[i].img->size_line, &main->tex[i].img->endian)))
            error(E_TEX);
        i++;
    }
}

