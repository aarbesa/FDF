/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:46:01 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:46:03 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_structs.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define ISOMETRIC_COEF 1.65
# define THREE_DIM_COEF 0.782993
# define ESC 65307

int		main(int argc, char **argv);
void	ft_fdf(int argc, char **argv);

void	get_map(t_fdf *fdf);

int		ft_free_exit(char *message, t_fdf *fdf);
void	ft_free_tab(char **tab);

void	ft_image_creation(t_img *data, t_fdf *fdf);

void	draw(t_point *point_a, t_point *point_b, t_img *data);

char	**ft_split(char const *s, char c, t_fdf *fdf);
int		ft_atoi(const char *str);
char	*ft_strcat(char *s1, char *s2);

void	ft_center(t_fdf *fdf);
void	ft_drawing(t_img *img, t_fdf *fdf);
int		ft_close(t_fdf *fdf);

#endif