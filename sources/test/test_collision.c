/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:19:03 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/27 22:11:34 by anemesis         ###   ########.fr       */
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
	t_poly		polygon;
	t_sphere	sphere;
	int			j;
	int			i;

	(void)polygon;
	if (flag == 0)
		flag = 255;
	else
		flag = 0;
	// polygon = (t_poly){0, {0, 0, 1}, {0, -1, -1}, {0, 1, -1}, {0, 0, 0}};
	sphere = (t_sphere){0, {42000, 0, 0}, {0, 0, 0}, 100};
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
			if (i == 0 && (j == 0 || j == rt->screen.width - 1))
			{
				printf("pix.y = %f\n", pix.y);
				printf("ray.origin.y = %f\n", ray.origin.y);
			}
			// tmp = collide_poly(&ray, &polygon);
			tmp = collide_sphere(&ray, &sphere);
			if (isnan(tmp.x) != FP_NAN)
				my_mlx_pixel_put(&rt->back_buff, i, j,
					vec_to_color((t_color){255 - flag, 0 + flag, 0}));
			j++;
		}
		i++;
	}
}
