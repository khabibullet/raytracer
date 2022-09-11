/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 22:30:09 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/utils.h"

void	add_diffuse_component(t_ray **rays, int heigth, int width, t_scene *sc)
{
	register int	i;
	register int	j;
	t_color			diffuse;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			if (rays[i][i].collis.surface != NULL)
			{
				diffuse = current_ray_diffuse(&rays[i][j], sc, i, j);
				rays[i][j].color = add_colors(rays[i][j].color, diffuse);
			}
			++j;
		}
		++i;
	}
}
