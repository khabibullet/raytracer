/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:30:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 17:36:04 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/screen.h"

void	emit_rays(t_minirt *rt)
{
	int			j;
	int			i;
	t_pix		pix;

	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			pix = find_pix_coords(i, j,
					rt->screen.density, rt->screen.aspect_ratio);
			rt->screen.rays[i][j].coords = get_cam_to_pix_vec(\
							rt->scene.cam.direction, rt->scene.cam.focal, pix);
			rt->screen.rays[i][j].origin = add_vecs(\
							rt->screen.rays[i][j].coords, rt->scene.cam.coords);
			rt->screen.rays[i][j].coords = unit_vector(\
												rt->screen.rays[i][j].coords);
			j++;
		}
		i++;
	}
}
