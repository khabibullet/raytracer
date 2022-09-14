/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_specular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:32:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 19:29:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/utils.h"

static t_color	add_component(t_color light_col, float coef, t_ray *tmp_ray)
{
	t_color	component;

	coef = powf(coef, 20);
	component = *(t_color *)(tmp_ray->collis.surface);
	component = mix_colors(&(t_color){coef, coef, coef}, &component);
	component = mix_colors(&component, &light_col);
	return (component);
}

static float	calculate_coefficient(t_ray *ray)
{
	float	coef;
	t_vec	reflected;

	coef = 2 * dot_product(ray->collis.surf_normal, ray->coords);
	reflected = vec_multiply_nbr(&ray->collis.surf_normal, coef);
	reflected = subtract_vecs(&reflected, &ray->coords);
	coef = dot_product(unit_vector(reflected), unit_vector(ray->beam));
	return (coef);
}

t_color	current_ray_specular(t_ray *ray, t_scene *scene)
{
	int		num;
	float	coef;
	t_color	specular;
	t_ray	tmp;

	specular = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		tmp = *ray;
		tmp.coords = subtract_vecs(&scene->lights[num].coords, &tmp.origin);
		tmp.collis.distance = vector_len(&tmp.coords);
		tmp.coords = unit_vector(tmp.coords);
		if (!current_ray_nearest_collision(&tmp, scene, FAST))
		{
			coef = calculate_coefficient(&tmp);
			if (coef > 0)
				specular = add_colors(specular, add_component(\
									scene->lights[num].color, coef, &tmp));
		}
		num++;
	}
	return (specular);
}
