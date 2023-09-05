/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:06 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:08 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

static void	ft_move_up(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->y -= 10;
		point = point->next;
	}
}

static void	ft_move_left(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->x -= 10;
		point = point->next;
	}
}

static void	ft_move_down(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->y += 10;
		point = point->next;
	}
}

static void	ft_move_right(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		point->x += 10;
		point = point->next;
	}
}

void	ft_move(t_fdf *fdf, int key)
{
	if (key == UP_ARROW)
		ft_move_up(fdf);
	else if (key == LEFT_ARROW)
		ft_move_left(fdf);
	else if (key == DOWN_ARROW)
		ft_move_down(fdf);
	else if (key == RIGHT_ARROW)
		ft_move_right(fdf);
}
