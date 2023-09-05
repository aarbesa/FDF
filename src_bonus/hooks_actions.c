/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:02 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:04 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

void	ft_hook_alt_up(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->y -= point->z;
		point = point->next;
	}
}

void	ft_hook_alt_down(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->y += point->z;
		point = point->next;
	}
}

void	ft_hook_reset(t_fdf *fdf)
{
	fdf->rotation_var1 = 0.782993;
	fdf->rotation_var2 = 0.782993;
	fdf->rotation_var3 = 0.782993;
	fdf->rotation_var4 = 0.782993;
	ft_conversion_to_isometric_view(fdf);
	ft_center(fdf);
}

void	ft_zoom_in(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	if (point->truc < 10)
	{
		point->truc += 1;
		while (point)
		{
			point->y *= 0.8;
			point->x *= 0.8;
			point = point->next;
		}
		ft_center(fdf);
	}
}

void	ft_zoom_out(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	if (point->truc > -10)
	{
		point->truc -= 1;
		while (point)
		{
			point->y *= 1.2;
			point->x *= 1.2;
			point = point->next;
		}
	}
	ft_center(fdf);
}
