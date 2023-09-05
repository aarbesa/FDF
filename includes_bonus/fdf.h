/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:45:07 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:45:39 by aabdyli          ###   ########.fr       */
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

# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363
# define CENTER 99
# define UP 117
# define DOWN 100
# define RESET 114
# define S 115
# define Q 113
# define SPACE 32
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 55
# define MINUS 45
# define PLUS 61

int		main(int argc, char **argv);
void	ft_fdf(int argc, char **argv);

void	get_map(t_fdf *fdf);
void	ft_conversion_to_isometric_view(t_fdf *fdf);
int		ft_free_exit(char *message, t_fdf *fdf);
void	ft_free_tab(char **tab);

void	ft_image_creation(t_img *data, t_fdf *fdf);

void	draw(t_point *point_a, t_point *point_b, t_img *data);

char	**ft_split(char const *s, char c, t_fdf *fdf);
int		ft_atoi(const char *str);
char	*ft_strcat(char *s1, char *s2);

void	ft_center(t_fdf *fdf);
void	ft_drawing(t_img *img, t_fdf *fdf);

void	ft_move(t_fdf *fdf, int key);

void	ft_zoom_out(t_fdf *fdf);
void	ft_zoom_in(t_fdf *fdf);
void	ft_hook_reset(t_fdf *fdf);
void	ft_hook_alt_down(t_fdf *fdf);
void	ft_hook_alt_up(t_fdf *fdf);

int		ft_close(t_fdf *fdf);

void	ft_hook_rotations(int key, t_fdf *fdf);

#endif