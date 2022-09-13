/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_specular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:32:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 15:09:31 by anemesis         ###   ########.fr       */
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

	(void)i;
	(void)j;
	specular = (t_color){0};
	num = 0;
	while (num < scene->num_of.lights)
	{
		if (!current_ray_nearest_collision(ray, scene, FAST, i, j))
		{
			coef = 2 * dot_product(ray->collis.surf_normal, ray->coords);
			reflected = vec_multiply_nbr(&ray->collis.surf_normal, coef);
			reflected = subtract_vecs(&reflected, &ray->coords);
			coef = dot_product(unit_vector(reflected), unit_vector(ray->beam));
			if (coef > 0)
			{
				coef = powf(coef, 10);
				component = *(t_color *)(ray->collis.surface);
				component = mix_colors(&(t_color){coef, coef, coef}, &component);
				component = mix_colors(&component, &scene->lights[num].color);
				specular = add_colors(specular, component);
			}
		}
		num++;
	}
	return (specular);
}
