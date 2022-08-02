/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:52:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 20:48:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	colorize_buffer(t_img *buffer, t_ray **rays, t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < screen->heigth)
	{
		j = 0;
		while (j < screen->width)
		{
			my_mlx_pixel_put(buffer, j, i, vec_to_color(rays[i][j].color));
			j++;
		}
		i++;
	}
}
