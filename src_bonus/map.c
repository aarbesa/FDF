/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:23 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:25 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf.h"

static void		get_img_in_linked_chain(t_fdf *fdf, char *buffer, int y);
static t_point	*ft_lstnew_point(int x, int y, float z, t_fdf *fdf);

void	get_map(t_fdf *fdf)
{
	int		fd;
	int		y;
	char	*buffer;

	fd = open(fdf->file_path, O_RDONLY);
	if (fd == -1)
		ft_free_exit("OPEN ERROR", fdf);
	buffer = NULL;
	fdf->point = NULL;
	y = 0;
	fdf->max_lenght = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		get_img_in_linked_chain(fdf, buffer, y);
		y++;
		free(buffer);
	}
	fdf->height = y;
	close(fd);
	if (!fdf->point)
		ft_free_exit("No valid data", fdf);
}

static void	get_img_in_linked_chain(t_fdf *fdf, char *buffer, int y)
{
	char	**tab_split;
	int		x;
	float	z;
	t_point	*point;
	t_point	*temp;

	tab_split = ft_split(buffer, ' ', fdf);
	x = 0;
	temp = fdf->point;
	while (temp && temp->next)
		temp = temp->next;
	while (tab_split[x] && tab_split[x][0] && tab_split[x][0] != '\n')
	{
		z = ft_atoi(tab_split[x]);
		point = ft_lstnew_point(x, y, z, fdf);
		if (temp)
			temp->next = point;
		else
			fdf->point = point;
		point->previous = temp;
		temp = point;
		x++;
	}
	ft_free_tab(tab_split);
	return ;
}

static t_point	*ft_lstnew_point(int x, int y, float z, t_fdf *fdf)
{
	t_point	*point;

	point = ft_calloc(sizeof(t_point), 1);
	if (!point)
		ft_free_exit("Malloc lstnew", fdf);
	point->x = x;
	point->y = y;
	point->z = (long long)z % 10000;
	point->line = y;
	if (x > fdf->max_lenght)
		fdf->max_lenght = x;
	point->column = x;
	point->y0 = -1;
	point->truc = 0;
	point->x0 = -1;
	point->next = NULL;
	point->previous = NULL;
	return (point);
}
