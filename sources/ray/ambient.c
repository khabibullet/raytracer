/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:14:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/15 12:30:43 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/collision.h"
#include "../../headers/parsing.h"

static inline t_color	maximize_brightness(t_color color)
{
	float	max;

	max = color.r;
	if (color.g > max)
		max = color.g;
	if (color.b > max)
		max = color.b;
	max = 255.0F / max;
	color.r *= max;
	color.g *= max;
	color.b *= max;
	return (color);
}

void	add_ambient_component(t_ray **rays, t_color	*ambient, int heigth, \
																	int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			if (rays[i][j].collis.surface != NULL)
			{
				rays[i][j].color = add_colors(rays[i][j].color, mix_colors(\
							(t_color *)(rays[i][j].collis.surface), ambient));
				if (rays[i][j].collis.surf_type == BULB)
					rays[i][j].color = maximize_brightness(rays[i][j].color);
			}
			++j;
		}
		++i;
	}
}

void	brighten_ambient(t_ray **rays, int heigth, int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			if (rays[i][j].collis.surface != NULL \
										&& rays[i][j].collis.surf_type != BULB)
			{
				rays[i][j].color.r *= 2;
				rays[i][j].color.g *= 2;
				rays[i][j].color.b *= 2;
			}
			++j;
		}
		++i;
	}
}
