/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_diffuse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:46 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 23:01:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/utils.h"

static t_color	add_component(t_color light_col, float coef, t_ray *tmp_ray)
{
	t_color	component;

	component = *(t_color *)(tmp_ray->collis.surface);
	component = mix_colors(&(t_color){coef, coef, coef}, &component);
	component = mix_colors(&component, &light_col);
	return (component);
}

t_color	current_ray_diffuse(t_ray *ray, t_scene *scene)
{
	int		num;
	float	coef;
	t_color	diffuse;
	t_ray	tmp_ray;

	diffuse = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		tmp_ray = *ray;
		tmp_ray.coords = subtract_vecs(&scene->lights[num].coords, \
															&tmp_ray.origin);
		tmp_ray.collis.distance = vector_len(&tmp_ray.coords);
		tmp_ray.coords = unit_vector(tmp_ray.coords);
		if (!current_ray_nearest_collision(&tmp_ray, scene, FAST))
		{
			coef = dot_product(tmp_ray.coords, tmp_ray.collis.surf_normal) \
						* scene->norm_coef / powf(tmp_ray.collis.distance, 2);
			diffuse = add_colors(diffuse, add_component(\
									scene->lights[num].color, coef, &tmp_ray));
		}
		num++;
	}
	return (diffuse);
}
