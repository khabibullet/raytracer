/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:19:03 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 00:01:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/color.h"
#include "../../headers/scene.h"
#include "../../headers/collision.h"
#include "../../headers/screen.h"

void	test_collision(t_minirt *rt)
{
	static int	flag;
	t_ray		ray;
	t_pix		pix;
	t_vec		tmp;
	int			j;
	int			i;

	if (flag == 0)
		flag = 255;
	else
		flag = 0;
	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			pix = find_pix_coords(i, j,
					rt->screen.density, rt->screen.aspect_ratio);
			ray.coords = get_cam_to_pix_vec(rt->scene.cam.direction,
					rt->scene.cam.focal, pix);
			ray.origin = ray.coords;
			// tmp = collide_plane(&ray, &plane);
			// if (isnan(tmp.x) != FP_NAN)
			// 	my_mlx_pixel_put(&rt->back_buff, j, i,
			// 		vec_to_color((t_color){255 - flag, 0 + flag, 0}));
			// tmp = collide_poly(&ray, &polygon);
			// if (isnan(tmp.x) != FP_NAN)
			// 	my_mlx_pixel_put(&rt->back_buff, j, i,
			// 		vec_to_color((t_color){255 - flag, 0 + flag, 255}));
			// tmp = collide_sphere(&ray, &sphere);
			if (isnan(tmp.x) != FP_NAN)
				my_mlx_pixel_put(&rt->phong_buffer, j, i,
					vec_to_color((t_color){flag, 255 - flag, 0}));
			j++;
		}
		i++;
	}
}
