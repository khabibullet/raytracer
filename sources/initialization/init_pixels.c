/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:51:01 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 16:36:42 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/initialization.h"

void	init_pixels(t_minirt *rt)
{
	int	i;
	int	j;

	rt->screen.pixels = safe_malloc(sizeof(*rt->screen.pixels) \
														* rt->screen.heigth);
	i = 0;
	while (i < rt->screen.heigth)
	{
		rt->screen.pixels[i] = safe_malloc(sizeof(**rt->screen.pixels) \
															* rt->screen.width);
		j = 0;
		while (j < rt->screen.width)
		{
			rt->screen.pixels[i][j] = find_pix_coords(i, j, &rt->screen);
			j++;
		}
		i++;
	}
}
