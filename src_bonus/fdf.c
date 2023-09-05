/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:43:39 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:43:41 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

static void	mlx_image_init(t_fdf *fdf, t_img *img);
static void	mlx_image_activation(t_fdf *fdf);
static int	ft_key_hook(int key, t_fdf *fdf);
static void	ft_expose_hook(t_fdf *fdf);

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
	fdf.rotation_var1 = 0.782993;
	fdf.rotation_var2 = 0.782993;
	fdf.rotation_var3 = 0.782993;
	fdf.rotation_var4 = 0.782993;
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
	else if (key == UP_ARROW || key == DOWN_ARROW || key == LEFT_ARROW || \
		key == RIGHT_ARROW)
		ft_move(fdf, key);
	if (key == CENTER)
		ft_center(fdf);
	if (key == ONE || key == TWO || key == THREE || key == FOUR || \
		key == FIVE || key == S || key == Q || key == SPACE)
		ft_hook_rotations(key, fdf);
	if (key == UP)
		ft_hook_alt_up(fdf);
	if (key == DOWN)
		ft_hook_alt_down(fdf);
	if (key == RESET)
		ft_hook_reset(fdf);
	if (key == PLUS)
		ft_zoom_in(fdf);
	if (key == MINUS)
		ft_zoom_out(fdf);
	ft_expose_hook(fdf);
	return (0);
}

static void	ft_expose_hook(t_fdf *fdf)
{
	t_img	*img;

	img = fdf->img;
	img->img_ptr = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_line, &img->endian);
	ft_drawing(img, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	fdf->img->img_ptr = NULL;
}
