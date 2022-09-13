/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 20:23:31 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/parsing.h"

void	add_specular_component(t_ray **rays, int heigth, int width, t_scene *sc)
{
	register int	i;
	register int	j;
	t_color			specular;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			if (rays[i][j].collis.surface != NULL && rays[i][j].collis.surf_type != BULB)
			{
				specular = current_ray_specular(&rays[i][j], sc, i, j);
				rays[i][j].color = add_colors(rays[i][j].color, specular);
			}
			++j;
		}
		++i;
	}
}
