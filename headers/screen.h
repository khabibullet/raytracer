/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:07 by enoye             #+#    #+#             */
/*   Updated: 2022/06/22 15:46:18 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "minirt.h"

typedef struct s_pix
{
	float	x;
	float	y;
}	t_pix;

typedef struct t_img
{
	void	*img;
	int		depth;
	int		len;
	int		end;
	char	*addr;
}	t_img;

t_pix	find_pix_coords(int i, int j, float density, float ratio);
void	my_mlx_pixel_put(t_img *pic, int x, int y, unsigned int color);

#endif