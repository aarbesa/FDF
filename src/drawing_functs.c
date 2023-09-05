/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:46:24 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:46:26 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

typedef struct s_draw
{
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}			t_draw;

static void	ft_do_draw_loop(t_img *img, t_draw plot, int color);
static void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	draw(t_point *point_a, t_point *point_b, t_img *img)
{
	t_draw	plot;
	int		color;

	plot.x0 = point_a->x;
	plot.y0 = point_a->y;
	plot.x1 = point_b->x;
	plot.y1 = point_b->y;
	color = 0x0000ff;
	if (point_b->z != point_a->z)
		color = 0xff0000;
	if (point_b->z == point_a->z && point_b->z != 0)
		color = 0xffffff;
	plot.dx = abs(plot.x1 - plot.x0);
	plot.dy = -abs(plot.y1 - plot.y0);
	if (plot.x0 < plot.x1)
		plot.sx = 1;
	else
		plot.sx = -1;
	if (plot.y0 < plot.y1)
		plot.sy = 1;
	else
		plot.sy = -1;
	plot.err = plot.dx + plot.dy;
	ft_do_draw_loop(img, plot, color);
}

static void	ft_do_draw_loop(t_img *img, t_draw plot, int color)
{
	while (1)
	{
		my_mlx_pixel_put(img, plot.x0, plot.y0, color);
		if (plot.x0 == plot.x1 && plot.y0 == plot.y1)
			break ;
		plot.e2 = 2 * plot.err;
		if (plot.e2 >= plot.dy)
		{
			plot.err = plot.dy + plot.err;
			plot.x0 += plot.sx;
		}
		if (plot.e2 <= plot.dx)
		{
			plot.err += plot.dx;
			plot.y0 += plot.sy;
		}
	}
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && y < WINDOW_HEIGHT && x < WINDOW_WIDTH)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
