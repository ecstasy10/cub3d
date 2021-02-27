/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:01:26 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/28 19:25:56 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init(t_main *main)
{
    main->sprite = (t_dvec*)malloc(sizeof(t_dvec));
}

int		main(int ac, char **av)
{
    t_main main;

    ft_bzero(&main, sizeof(t_main));
    init(&main);
    if (ac > 3)
        error(E_ARGS);
    else if (ac >= 2 && fileExtensionCheck(av[1], "cub"))
    {
        fileConfigValidator(&main, av[1]);
        sprite_init(&main, main.sprite_count);
         if (ac == 3 && fileFlagCheck(av[2], "--save"))
             bitmap_save(&main);
         else if (ac == 3)
             error(E_FLAG);
        window_initialize(&main);
    } else if (ac >= 2 && !fileExtensionCheck(av[1], "cub"))
        error(E_MAP_FILE_EXT);
    else
        error(E_ARGS);
    return (0);
}
