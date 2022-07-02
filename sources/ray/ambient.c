/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:30:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/29 16:33:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	add_amb_component(t_minirt *rt)
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
			rt->screen.rays[i][j].origin = rt->screen.rays[i][j].coords;
			get_all_collisions(rt);
			my_mlx_pixel_put(&rt->back_buff, j, i, \
								vec_to_color((t_color){flag, 255 - flag, 0}));
			j++;
		}
		i++;
	}
}
