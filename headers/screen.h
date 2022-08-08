/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:07 by enoye             #+#    #+#             */
/*   Updated: 2022/08/08 14:31:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "../libraries/libmlx/headers/mlx.h"
# include "vector.h"
# include "scene.h"

typedef struct s_ray	t_ray;
typedef struct s_minirt	t_minirt;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_pix
{
	float	x;
	float	y;
}	t_pix;

typedef struct s_img
{
	void	*ptr;
	int		depth;
	int		len;
	int		end;
	char	*addr;
}	t_img;

typedef struct s_fps
{
	char			str[10];
	int				x_pos;
	int				y_pos;
	unsigned int	color;
}	t_fps;

typedef struct s_screen
{
	int			width;
	int			heigth;
	float		aspect_ratio;
	t_vec		hor_axis;
	t_vec		ver_axis;
	float		density;
	t_ray		**rays;
	t_pix		**pixels;
	t_fps		fps;
}	t_screen;

t_pix	find_pix_coords(int i, int j, t_screen *screen);
void	my_mlx_pixel_put(t_img *pic, int x, int y, unsigned int color);
t_vec	cam_to_pix_vec(t_cam *cam, t_pix *pix_coords, t_screen *screen);
void	find_screen_axes(t_screen *screen, t_vec *direction);
void	put_fps(void *mlx_ptr, void *mlx_win, t_fps *fps);

#endif