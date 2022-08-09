/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_diffuse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:46 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 18:59:32 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

t_color	current_ray_diffuse(t_ray *ray, t_scene *scene, float c)
{
	t_color	diffuse;
	t_vec	surf_to_light;
	int		i;
	t_vec	tmp;
	t_color	res;

	diffuse = (t_color){0};
	i = 0;
	while (i < scene->num_of.lights)
	{
		surf_to_light = subtract_vecs(&scene->lights[i].coords, &ray->origin);
		ray->collis.distance = vector_len(&surf_to_light);
		tmp = ray->coords;
		ray->coords = unit_vector(surf_to_light);
		if (!current_ray_nearest_collision(ray, scene, FAST))
		res = mix_colors((t_color *)(&ray->collis.surface), \
														&(t_color){c, c, c});
		diffuse = add_colors(diffuse, mix_colors(&res, \
													&scene->lights[i].color));
		ray->coords = tmp;
		i++;
	}
	return (diffuse);
}
