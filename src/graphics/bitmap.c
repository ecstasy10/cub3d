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

void	pixel_data_write(int fd, t_main *main)
{
    char	*pixel_data;
    int		i;

    i = 0;
    pixel_data = (char*)main->img.buffer;
    while (i < main->win.height)
        write(fd, &pixel_data[i++ * (main->img.size_line * 4)],
              main->win.width * 16);
}

void	infoheader_write(int fd, t_main *main)
{
    static unsigned char	infoheader[40];

    ft_bzero(infoheader, sizeof(infoheader));
    infoheader[0] = (unsigned char)sizeof(infoheader);
    infoheader[4] = (unsigned char)(main->win.width);
    infoheader[5] = (unsigned char)(main->win.width >> 8);
    infoheader[6] = (unsigned char)(main->win.width >> 16);
    infoheader[7] = (unsigned char)(main->win.width >> 24);
    infoheader[8] = (unsigned char)(-main->win.height);
    infoheader[9] = (unsigned char)(-main->win.height >> 8);
    infoheader[10] = (unsigned char)(-main->win.height >> 16);
    infoheader[11] = (unsigned char)(-main->win.height >> 24);
    infoheader[12] = (unsigned char)1;
    infoheader[14] = (unsigned char)32;
    write(fd, infoheader, 40);
}

void	fileheader_write(int fd, t_main *main)
{
    static unsigned char	fileheader[14];
    int						size_file;

    ft_bzero(fileheader, sizeof(fileheader));
    size_file = 54 + (main->win.width * main->win.height * 4);
    fileheader[0] = (unsigned char)0x42;
    fileheader[1] = (unsigned char)0x4D;
    fileheader[2] = (unsigned char)(size_file);
    fileheader[3] = (unsigned char)(size_file >> 8);
    fileheader[4] = (unsigned char)(size_file >> 16);
    fileheader[5] = (unsigned char)(size_file >> 24);
    fileheader[10] = (unsigned char)54;
    write(fd, fileheader, 14);
}

int		bitmap_save(t_main *main)
{
    int		fd;

    if (!(fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)))
        return (0);
    fileheader_write(fd, main);
    infoheader_write(fd, main);
    main->mlx.ptr = mlx_init();
    main->win.ptr = mlx_new_window(main->mlx.ptr, main->win.width,
                                  main->win.height, "cub3D");
    speed_initialize(main);
    texture_initialize(main);
    image_render(main);
    pixel_data_write(fd, main);
    mlx_destroy_image(main->mlx.ptr, main->img.ptr);
    ft_putstr_fd("Bitmap image file created!\n", 1);
    close(fd);
    program_exit(main);
    return (1);
}
