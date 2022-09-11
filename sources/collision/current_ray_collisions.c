/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_collisions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:54:34 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 10:44:39 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

int	current_ray_nearest_collision(t_ray *ray, t_scene *scene, int mode)
{
	int	i;

	i = -1;
	while (++i < scene->num_of.cylinders)
		if (collide_cylinder(ray, &scene->cylinders[i], mode) && mode == FAST)
			return (1);
	i = -1;
	while (++i < scene->num_of.planes)
		if (collide_plane(ray, &scene->planes[i], mode) && mode == FAST)
			return (1);
	i = -1;
	while (++i < scene->num_of.polygons)
		if (collide_poly(ray, &scene->polygons[i], mode) && mode == FAST)
			return (1);
	while (++i < scene->num_of.spheres)
		if (collide_sphere(ray, &scene->spheres[i], mode) && mode == FAST)
			return (1);
	i = -1;
	return (0);
}
