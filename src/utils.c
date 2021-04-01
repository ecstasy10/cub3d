/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:56:29 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/04/01 11:56:39 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	dist(double x1, double x2)
{
	return (sqrt(1 + (pow(x1, 2) / pow(x2, 2))));
}

int	valid_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen_only_color(char *str)
{
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	while (str[l] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != 'F' && str[i] != 'C')
			l++;
		i++;
	}
	return (l);
}

char	*ft_strtrim_color(char *str)
{
	char	*copy;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen_only_color(str);
	copy = (char *) malloc(sizeof(char ) * (l + 1));
	if (!copy)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != 'F' && str[i] != 'C')
		{
			copy[l] = str[i];
			l++;
		}
		i++;
	}
	copy[l] = '\0';
	return (copy);
}
