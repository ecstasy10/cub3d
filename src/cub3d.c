/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:01:26 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/23 19:03:39 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		main(int ac, char **av)
{
    if (ac >= 2 && ft_fileExtensionCheck(av[1], "cub"))
    {
         printf("%d", (ac == 3 && ft_flagCheck(av[2], "--save")));
    } else
        write(2, "Error : Invalid arguments\n", 26);
    return (0);
}
