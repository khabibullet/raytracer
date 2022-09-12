/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_diffuse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:46 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/12 19:53:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/utils.h"

t_color	current_ray_diffuse(t_ray *ray, t_scene *scene, int i, int j)
{
	int		num;
	float	coef;
	t_color	diffuse;
	t_color	component;

	(void)i;
	(void)j;
	diffuse = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		ray->coords = subtract_vecs(&scene->lights[num].coords, &ray->origin);
		ray->collis.distance = vector_len(&ray->coords);
		ray->coords = unit_vector(ray->coords);
		if (!current_ray_nearest_collision(ray, scene, FAST, i, j))
		{
			coef = dot_product(ray->coords, ray->collis.surf_normal);
			component = *(t_color *)(ray->collis.surface);
			component = mix_colors(&(t_color){coef, coef, coef}, &component);
			component = mix_colors(&component, &scene->lights[num].color);
			diffuse = add_colors(diffuse, component);
		}
		num++;
	}
	return (diffuse);
}
