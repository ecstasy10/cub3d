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

void		my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char	*dst;

    dst = img->buffer + (y * img->size_line + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void		vertical_draw(t_main *main, int x, int i)
{
    int	y;
    int	color;

    y = 0;
    while (y < main->win.height)
    {
        if (y < main->draw.start)
            my_mlx_pixel_put(&main->img, x, y, main->draw.c_rgb);
        if (y >= main->draw.start && y <= main->draw.end)
        {
            main->tex[i].y = (int)main->tex[i].pos & (main->tex[i].height - 1);
            main->tex[i].pos += main->tex[i].step;
            color = main->tex[i].img->buff[main->tex[i].height *
                                          main->tex[i].y + main->tex[i].x];
            my_mlx_pixel_put(&main->img, x, y, color);
        }
        if (y > main->draw.end)
            my_mlx_pixel_put(&main->img, x, y, main->draw.f_rgb);
        y++;
    }
}

static void	sprite_texture_x_calculate(t_main *main, int x)
{
    main->tex[4].x = (int)(256 * (x - (main->draw.sprite.win -
                                      main->draw.sprite.width / 2)) * main->tex[4].width /
                          main->draw.sprite.width) / 256;
}

static void	sprite_texture_y_calculate(t_main *main, int y)
{
    main->tex[4].y = (((y * 256 - main->win.height * 128 +
                       main->draw.sprite.height * 128) *
                      main->tex[4].height) / main->draw.sprite.height) / 256;
}

void		sprite_draw(t_main *main)
{
    int	x;
    int	y;
    int	color;

    x = main->draw.sprite.start.x;
    while (x < main->draw.sprite.end.x && x <= main->win.width)
    {
        sprite_texture_x_calculate(main, x);
        if (x >= 0 && main->draw.sprite.transform.y > 0 &&
            main->draw.sprite.transform.y < main->draw.z_buffer[x])
        {
            y = main->draw.sprite.start.y;
            while (y < main->draw.sprite.end.y && y <= main->win.height + 1)
            {
                sprite_texture_y_calculate(main, y);
                color = main->tex[4].img->buff[main->tex[4].width *
                                              main->tex[4].y + main->tex[4].x];
                if (color != 0)
                    my_mlx_pixel_put(&main->img, x, y, color);
                y++;
            }
        }
        x++;
    }
}
