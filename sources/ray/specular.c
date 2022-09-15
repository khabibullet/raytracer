/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/15 15:52:02 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/parsing.h"

void	add_specular_component(t_ray **rays, t_screen *screen, t_scene *sc)
{
	register int	i;
	register int	j;
	t_color			specular;

	i = 0;
	while (i < screen->heigth)
	{
		j = 0;
		while (j < screen->width)
		{
			if (rays[i][j].collis.surface != NULL \
										&& rays[i][j].collis.surf_type != BULB)
			{
				specular = current_ray_specular(&rays[i][j], sc);
				rays[i][j].color = add_colors(rays[i][j].color, specular);
			}
			++j;
		}
		++i;
	}
}
