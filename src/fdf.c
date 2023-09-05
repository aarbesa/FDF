/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:46:28 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:46:29 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mlx_image_init(t_fdf *fdf, t_img *img);
static void	mlx_image_activation(t_fdf *fdf);
static int	ft_key_hook(int key, t_fdf *fdf);

void	ft_fdf(int argc, char **argv)
{
	t_fdf	fdf;
	t_img	img;

	if (argc != 2)
	{
		write(2, "Incorrect arguments.\n", 22);
		exit(EXIT_FAILURE);
	}
	mlx_image_init(&fdf, &img);
	fdf.file_path = argv[1];
	ft_image_creation(&img, &fdf);
	mlx_image_activation(&fdf);
	ft_free_exit("END", &fdf);
}

void	mlx_image_init(t_fdf *fdf, t_img *img)
{
	fdf->img = NULL;
	fdf->mlx_win = NULL;
	fdf->point = NULL;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_free_exit("mlx_init", fdf);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "Arbesa's FdF");
	if (!fdf->mlx_win)
		ft_free_exit("mlx_new_window", fdf);
	img->img_ptr = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img->img_ptr)
		ft_free_exit("mlx_new_image", fdf);
	fdf->img = img;
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_line, &img->endian);
}

static void	mlx_image_activation(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	fdf->img->img_ptr = NULL;
	mlx_hook(fdf->mlx_win, 2, 1L << 0, ft_key_hook, fdf);
	mlx_hook(fdf->mlx_win, 17, 1L << 17, ft_close, fdf);
	mlx_loop(fdf->mlx);
}

static int	ft_key_hook(int key, t_fdf *fdf)
{
	if (key == ESC)
		ft_free_exit("End of Fdf", fdf);
	return (0);
}
