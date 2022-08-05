/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:30:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/05 13:36:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	emit_rays(t_minirt *rt)
{
	int			j;
	int			i;

	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			rt->screen.rays[i][j].coords = cam_to_pix_vec(&rt->scene.cam, \
										&rt->screen.pixels[i][j], &rt->screen);
			rt->screen.rays[i][j].origin = add_vecs(rt->scene.cam.coords, \
												rt->screen.rays[i][j].coords);
			rt->screen.rays[i][j].coords = unit_vector(\
												rt->screen.rays[i][j].coords);
			j++;
		}
		i++;
	}
}
