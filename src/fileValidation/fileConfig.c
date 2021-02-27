/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileConfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:45:13 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/29 19:45:14 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		color_rgb_to_hex(unsigned r, unsigned g, unsigned b)
{
    int	color;

    color = r & 0xFF;
    color <<= 8;
    color |= g & 0xFF;
    color <<= 8;
    color |= b & 0xFF;
    return (color);
}

void    validateColors(t_main *main, char **colorLine)
{
    char    **rgb;

    rgb = ft_split(colorLine[1], ',');
    if (!ft_strcmp(colorLine[0], "F"))
        main->draw.f_rgb = color_rgb_to_hex(atoi(rgb[0]), atoi(rgb[1]), atoi(rgb[2]));
    else if (!ft_strcmp(colorLine[0], "C"))
        main->draw.c_rgb = color_rgb_to_hex(atoi(rgb[0]), atoi(rgb[1]), atoi(rgb[2]));
}

void    setTexture(t_main *main, char *texture, int is_sprite)
{
    if (main->tex_it < 5)
    {
        main->tex[main->tex_it].path = ft_strdup(texture);
        printf("%s\n", main->tex[main->tex_it].path);
        main->tex[main->tex_it].is_sprite = is_sprite;
        main->tex_it++;
    } else
        error(E_TEX);
}

int     validateTextures(t_main *main, char **texturesLine)
{
    if (((fileExtensionCheck(texturesLine[1], "xpm")
        || fileExtensionCheck(texturesLine[1], "png"))
        && ft_is_valid_file(texturesLine[1]))
        && (ft_memcmp(texturesLine[0], "NO", 2) == 0
            || ft_memcmp(texturesLine[0], "SO", 2) == 0
            || ft_memcmp(texturesLine[0], "WE", 2) == 0
            || ft_memcmp(texturesLine[0], "EA", 2) == 0
            || ft_memcmp(texturesLine[0], "S", 2) == 0))
        setTexture(main, texturesLine[1],
                   !!ft_memcmp(texturesLine[0], "S", 2) == 0);
    else
        error(E_TEX);
    return 0;
}

void     validateResolution(t_main *main, char **resolutionLine)
{
    if (ft_is_str_digit(resolutionLine[1]) && ft_atoi(resolutionLine[1]) > 1
        && ft_is_str_digit(resolutionLine[2]) && ft_atoi(resolutionLine[2]) > 1)
    {
        main->win.width = ft_atoi(resolutionLine[1]) > 1920 ? 1920 : ft_atoi(resolutionLine[1]);
        main->win.height = ft_atoi(resolutionLine[2]) > 1080 ? 1080 : ft_atoi(resolutionLine[1]);
    } else
        error(E_RES);
}
