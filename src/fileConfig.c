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

int     setResolution(t_main *main, char **resolutionLine)
{
    main->win.width = ft_isdigit(ft_atoi(resolutionLine[1]));
    printf("%s\n", resolutionLine[1]);
    return 0;
}
