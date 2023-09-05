/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:15 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:16 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

void	ft_drawing(t_img *img, t_fdf *fdf)
{
	t_point	*point;
	t_point	*temp;

	point = fdf->point;
	while (point->next)
	{
		if (point->line == point->next->line)
			draw(point, point->next, img);
		point = point->next;
	}
	point = fdf->point;
	while (point->next)
	{
		temp = point->next;
		while (temp->column != point->column && temp->next)
			temp = temp->next;
		if (temp->column == point->column)
			draw(point, temp, img);
		point = point->next;
	}
}

void	ft_image_creation(t_img *img, t_fdf *fdf)
{
	get_map(fdf);
	fdf->multi = (WINDOW_WIDTH / 2) / (fdf->height + fdf->max_lenght) + 1;
	ft_conversion_to_isometric_view(fdf);
	ft_center(fdf);
	ft_drawing(img, fdf);
}

void	ft_conversion_to_isometric_view(t_fdf *fdf)
{
	t_point	*point;
	float	x;
	float	y;

	point = fdf->point;
	while (point)
	{
		x = (point->x * fdf->multi);
		y = (point->y * fdf->multi);
		if (point->x0 == -1)
		{
			point->x0 = x;
			point->y0 = y;
		}
		x = point->x0;
		y = point->y0;
		point->x = x * cos(fdf->rotation_var1) - y * sin(fdf->rotation_var2);
		point->y = x * sin(fdf->rotation_var3) + y * cos(fdf->rotation_var4);
		point->y -= point->z * 3;
		point->x = (point->x / cos(ISOMETRIC_COEF)) * cos(ISOMETRIC_COEF + 0.1);
		point->y = (point->y / sin(ISOMETRIC_COEF)) * sin(ISOMETRIC_COEF + 0.1);
		point = point->next;
	}
}

void	ft_center(t_fdf *fdf)
{
	t_point	*point;
	int		center_column;
	int		center_line;
	int		diff_x;
	int		diff_y;

	point = fdf->point;
	center_column = fdf->max_lenght / 2;
	center_line = fdf->height / 2;
	while (point && !(point->column == center_column && \
		point->line == center_line))
		point = point->next;
	if (!point)
		return ;
	diff_x = (point->x - (WINDOW_WIDTH / 2));
	diff_y = (point->y - (WINDOW_HEIGHT / 2));
	point = fdf->point;
	while (point)
	{
		point->x -= diff_x;
		point->y -= diff_y;
		point = point->next;
	}
}
