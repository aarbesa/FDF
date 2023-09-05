/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:10 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:12 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

void	ft_key_one(t_fdf *fdf)
{
	fdf->rotation_var1 += 0.07;
	fdf->rotation_var2 += 0.07;
}

void	ft_key_two(t_fdf *fdf)
{
	fdf->rotation_var4 -= 0.07;
	fdf->rotation_var3 -= 0.07;
}

void	ft_key_three_and_four(int key, t_fdf *fdf)
{
	if (key == 39)
	{
		fdf->rotation_var3 -= 0.07;
		fdf->rotation_var4 += 0.07;
		return ;
	}
	fdf->rotation_var3 -= 0.07;
	fdf->rotation_var4 += 0.07;
	fdf->rotation_var2 -= 0.07;
	fdf->rotation_var1 += 0.07;
}

void	ft_two_dim(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->x = point->x0;
		point->y = point->y0;
		point = point->next;
	}
}

void	ft_hook_rotations(int key, t_fdf *fdf)
{
	if (key == Q)
	{
		fdf->rotation_var1 += 0.07;
		fdf->rotation_var2 += 0.07;
		fdf->rotation_var3 += 0.07;
		fdf->rotation_var4 += 0.07;
	}
	if (key == S)
	{
		fdf->rotation_var1 -= 0.07;
		fdf->rotation_var2 -= 0.07;
		fdf->rotation_var3 -= 0.07;
		fdf->rotation_var4 -= 0.07;
	}
	if (key == ONE)
		ft_key_one(fdf);
	if (key == TWO)
		ft_key_two(fdf);
	if (key == THREE || key == FOUR)
		ft_key_three_and_four(key, fdf);
	if (key == SPACE)
		ft_two_dim(fdf);
	if (key != SPACE)
		ft_conversion_to_isometric_view(fdf);
	ft_center(fdf);
}
