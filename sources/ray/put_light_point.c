/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_light_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:31:37 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 21:53:20 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

void	put_light_point(t_ray **rays, t_scene *scene, int heigth, \
																	int width)
{
	register int	i;
	register int	j;
	int				index[2];
	t_vec			cam_to_light;
	float			min_angle;
	float			tmp;

	cam_to_light = subtract_vecs(&scene->lights[0].coords, &scene->cam.coords);
	i = 0;
	min_angle = -1.0F;
	index[0] = -1;
	index[0] = -1;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			tmp = dot_product(cam_to_light, rays[i][j].coords);
			if (tmp > min_angle)
			{
				min_angle = tmp;
				index[0] = i;
				index[1] = j;
			}
			++j;
		}
		++i;
	}
	if (index[0] > 0 && index[1] > 0)
	{
		rays[index[0]][index[1]].color = (t_color){255, 255, 255};
		rays[index[0] + 1][index[1] + 1].color = (t_color){255, 255, 255};
		rays[index[0] + 1][index[1] - 1].color = (t_color){255, 255, 255};
		rays[index[0] - 1][index[1] + 1].color = (t_color){255, 255, 255};
		rays[index[0] - 1][index[1] - 1].color = (t_color){255, 255, 255};
	}
}
