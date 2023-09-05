/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:45:03 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:45:04 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include <sys/types.h> //open
# include <sys/stat.h> //open
# include <fcntl.h> //open
# include <math.h> //math

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					bpp;
	int					size_line;
	int					endian;
}			t_img;

typedef struct s_point
{
	float				x;
	float				y;
	float				y0;
	float				x0;
	int					truc;
	float				z;
	int					line;
	int					column;
	struct s_point		*previous;
	struct s_point		*next;
}			t_point;

typedef struct s_fdf
{
	float				multi;
	float				rotation_var1;
	float				rotation_var2;
	float				rotation_var3;
	float				rotation_var4;
	char				*file_path;
	t_point				*point;
	int					max_lenght;
	int					height;
	t_img				*img;
	void				*mlx;
	void				*mlx_win;
}			t_fdf;

#endif