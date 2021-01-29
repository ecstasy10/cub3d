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

#include "../cub3d.h"

int		main(int ac, char **av)
{
    t_main main;

    ft_bzero(&main, sizeof(t_main));
    if (ac >= 2 && fileExtensionCheck(av[1], "cub"))
    {
         if (ac == 3 && fileFlagCheck(av[2], "--save"))
             return 22;
        fileConfigValidator(&main, av[1]);
    } else
        write(2, "Error : Invalid arguments\n", 26);
    return (0);
}