/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:12:02 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/27 19:50:32 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

void	fill_buffer_color(t_img *buff, int w, int h, unsigned int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			my_mlx_pixel_put(buff, x, y, color);
			x++;
		}
		y++;
	}
}
