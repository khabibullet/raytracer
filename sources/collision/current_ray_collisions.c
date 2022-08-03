/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_ray_collisions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:54:34 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/03 21:05:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

void	current_ray_nearest_collision(t_ray *ray, t_scene *scene)
{
	int	i;

	// printf("cyl center: (%f, %f, %f)\n", scene->cylinders[0].center.x, scene->cylinders[0].center.y, scene->cylinders[0].center.z);
	// printf("cyl axis: (%f, %f, %f)\n\n", scene->cylinders[0].axis.x, scene->cylinders[0].axis.y, scene->cylinders[0].axis.z);
	// printf("origin: (%f, %f, %f)\n", ray->origin.x, ray->origin.y, ray->origin.z);
	// printf("coords: (%f, %f, %f)\n\n", ray->coords.x, ray->coords.y, ray->coords.z);
	i = -1;
	while (++i < scene->num_of.cylinders)
		collide_cylinder(ray, &scene->cylinders[i]);
	// i = -1;
	// while (++i < scene->num_of.spheres)
	// 	collide_sphere(ray, &scene->spheres[i]);
	// i = -1;
	// while (++i < scene->num_of.planes)
	// 	collide_plane(ray, &scene->planes[i]);
	// i = -1;
	// while (++i < scene->num_of.polygons)
	// 	collide_poly(ray, &scene->polygons[i]);
}
