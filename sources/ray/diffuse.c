/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 18:55:09 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

void	add_diffuse_component(t_ray **rays, int heigth, int width, t_scene *sc)
{
	register int	i;
	register int	j;
	t_color			diffuse;
	float			coef;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			coef = dot_product(&rays[i][j].collis.surf_normal, \
															&rays[i][j].coords);
			diffuse = current_ray_diffuse(&rays[i][j], sc, coef);
			rays[i][j].color = add_colors(rays[i][j].color, diffuse);
			++j;
		}
		++i;
	}
}
