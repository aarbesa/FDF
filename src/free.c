/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:46:32 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:46:33 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fdf_free_points(t_point *point);

int	ft_free_exit(char *message, t_fdf *fdf)
{
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 2);
	}
	if (fdf->point)
		ft_fdf_free_points(fdf->point);
	if (fdf->img && fdf->img->img_ptr)
		mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
	if (fdf->mlx_win)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->mlx)
		free(fdf->mlx);
	exit(0);
	return (0);
}

static void	ft_fdf_free_points(t_point *point)
{
	t_point	*temp;

	while (point->next)
	{
		temp = point->next;
		free (point);
		point = temp;
	}
	free (point);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_close(t_fdf *fdf)
{
	ft_free_exit("End of Fdf", fdf);
	return (0);
}
