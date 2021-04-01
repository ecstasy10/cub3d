/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:07:00 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/08 13:10:50 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_put(int errno)
{
	ft_putstr_fd(HEADER, 1);
	ft_putstr_fd(TITLE, 1);
	if (errno == 1)
		ft_putstr_fd(E_ARGS, 1);
	else if (errno == 2)
		ft_putstr_fd(E_FLAG, 1);
	else if (errno == 3)
		ft_putstr_fd(E_FILE, 1);
	else if (errno == 4)
		ft_putstr_fd(E_FILE_404, 1);
	else if (errno == 5)
		ft_putstr_fd(E_FILE_INFO, 1);
	else if (errno == 6)
		ft_putstr_fd(E_FILE_MAP_404, 1);
	else if (errno == 7)
		ft_putstr_fd(E_RES, 1);
	else if (errno == 8)
		ft_putstr_fd(E_TEX, 1);
	else if (errno == 9)
		ft_putstr_fd(E_COLOR, 1);
	else if (errno == 10)
		ft_putstr_fd(E_MAP_DESC, 1);
	else if (errno == 11)
		ft_putstr_fd(E_PLAYER_POS, 1);
	else if (errno == 12)
		ft_putstr_fd(E_ERR, 1);
	ft_putstr_fd(FOOTER, 1);
	exit(EXIT_FAILURE);
}

int	program_exit(t_all *all)
{
	mlx_destroy_window(all->mlx.ptr, all->win.ptr);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (argc < 2 || argc > 3)
		error_put(1);
	if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		error_put(2);
	if (!ft_file_format_cmp(argv[1], ".cub"))
		error_put(3);
	config_parse(&all, argv[1]);
	if (!all.map_rows)
		error_put(6);
	sprite_init(&all, all.sprite_count);
	map_init(&all, argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		bitmap_save(&all);
	window_init(&all);
	return (1);
}
