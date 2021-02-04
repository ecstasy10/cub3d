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

void	error(char *Id)
{
    ft_putstr_fd(HEADER, 1);
    ft_putstr_fd(TITLE, 1);
    ft_putstr_fd(Id, 1);
    ft_putstr_fd(FOOTER, 1);
    exit(EXIT_FAILURE);
}