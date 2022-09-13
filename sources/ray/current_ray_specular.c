/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_specular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:32:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 21:02:45 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/utils.h"

t_color	current_ray_specular(t_ray *ray, t_scene *scene, int i, int j)
{
	int		num;
	float	coef;
	t_color	specular;
	t_color	component;
	t_vec	reflected;
	t_ray	tmp_ray;

	(void)i;
	(void)j;
	specular = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		tmp_ray = *ray;
		tmp_ray.coords = subtract_vecs(&scene->lights[num].coords, &tmp_ray.origin);
		tmp_ray.collis.distance = vector_len(&tmp_ray.coords);
		tmp_ray.coords = unit_vector(tmp_ray.coords);
		if (!current_ray_nearest_collision(&tmp_ray, scene, FAST, i, j))
		{
			coef = 2 * dot_product(tmp_ray.collis.surf_normal, tmp_ray.coords);
			reflected = vec_multiply_nbr(&tmp_ray.collis.surf_normal, coef);
			reflected = subtract_vecs(&reflected, &tmp_ray.coords);
			coef = dot_product(unit_vector(reflected), unit_vector(tmp_ray.beam));
			if (coef > 0)
			{
				coef = powf(coef, 20);
				component = *(t_color *)(tmp_ray.collis.surface);
				component = mix_colors(&(t_color){coef, coef, coef}, &component);
				component = mix_colors(&component, &scene->lights[num].color);
				specular = add_colors(specular, component);
			}
		}
		num++;
	}
	return (specular);
}
