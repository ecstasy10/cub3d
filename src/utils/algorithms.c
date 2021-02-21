/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/4 19:33:07 by dbalboa-           #+#    #+#             */
/*   Updated: 2021/02/4 19:33:10 by dbalboa-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	dist(double x1, double x2)
{
    return (sqrt(1 + (pow(x1, 2) / pow(x2, 2))));
}
