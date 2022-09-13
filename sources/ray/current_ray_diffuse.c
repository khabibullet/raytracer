/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_diffuse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:46 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 20:53:07 by anemesis         ###   ########.fr       */
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
	t_ray	tmp_ray;

	(void)i;
	(void)j;
	diffuse = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		tmp_ray = *ray;
		tmp_ray.coords = subtract_vecs(&scene->lights[num].coords, &tmp_ray.origin);
		tmp_ray.collis.distance = vector_len(&tmp_ray.coords);
		tmp_ray.coords = unit_vector(tmp_ray.coords);
		if (!current_ray_nearest_collision(&tmp_ray, scene, FAST, i, j))
		{
			coef = dot_product(tmp_ray.coords, tmp_ray.collis.surf_normal);
			component = *(t_color *)(tmp_ray.collis.surface);
			component = mix_colors(&(t_color){coef, coef, coef}, &component);
			component = mix_colors(&component, &scene->lights[num].color);
			diffuse = add_colors(diffuse, component);
		}
		num++;
	}
	return (diffuse);
}
