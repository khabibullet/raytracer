/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_diffuse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:46 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 23:12:39 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

t_color	current_ray_diffuse(t_ray *ray, t_scene *scene)
{
	int		i;
	float	coef;
	t_color	diffuse;
	t_color	component;

	diffuse = (t_color){0};
	i = 0;
	while (i < scene->num_of.lights)
	{
		ray->coords = subtract_vecs(&scene->lights[i].coords, &ray->origin);
		ray->collis.distance = vector_len(&ray->coords);
		ray->coords = unit_vector(ray->coords);
		if (!current_ray_nearest_collision(ray, scene, FAST))
		{
			coef = dot_product(&ray->coords, &ray->collis.surf_normal);
			component = *(t_color *)(&ray->collis.surface);
			component = mix_colors(&(t_color){coef, coef, coef}, &component);
			component = mix_colors(&component, &scene->lights[i].color);
			diffuse = add_colors(diffuse, component);
		}
		i++;
	}
	return (diffuse);
}
