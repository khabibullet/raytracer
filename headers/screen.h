/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:07 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 00:10:25 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "ray.h"

typedef struct s_ray	t_ray;

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

typedef struct s_screen
{
	int			width;
	int			heigth;
	float		aspect_ratio;
	float		density;
	t_ray		**rays;
}	t_screen;

t_pix	find_pix_coords(int i, int j, float density, float ratio);
void	my_mlx_pixel_put(t_img *pic, int x, int y, unsigned int color);
t_vec	get_cam_to_pix_vec(t_vec cam_dir, float focal, t_pix pix_coords);

#endif