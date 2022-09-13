/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:19:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 18:19:42 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/parsing.h"

/**
**	1)	If d (descriminant is below zero), then t1 (t[0]) and t2 (t[1]) are
**		imaginary numbers, which means ray does not intersect sphere.
**	2)	If t1 and 2 are positive numbers, then it means ray belongs the line, that
**		intersects sphere, but ray does not intersect sphere.
**		it means, that ray's origin is inside the sphere and ray intersect sphere
**		only once.
**	3)	If both t1 and t2 are positive, ray intersects sphere twice.
**/

static void	update_collision(t_ray *ray, t_sphere *sphere, float distance)
{
	t_vec	tmp;

	ray->collis.surface = (void *)sphere;
	ray->collis.distance = distance;
	tmp = vec_multiply_nbr(&ray->coords, distance);
	tmp = add_vecs(&ray->origin, &tmp);
	ray->collis.surf_normal = subtract_vecs(&tmp, &sphere->center);
	if (sphere->type == BULB)
		ray->collis.surf_type = BULB;
}

int	collide_sphere(t_ray *ray, t_sphere *sphere, int mode, int i, int j)
{
	float	coeffs[3];
	float	d;
	float	t[2];
	t_vec	co;

	(void)i;
	(void)j;
	// if (mode == FAST && sphere->type == BULB)
	// 	return (0);
	co = subtract_vecs(&ray->origin, &sphere->center);
	coeffs[0] = dot_product(ray->coords, ray->coords);
	coeffs[1] = 2 * dot_product(ray->coords, co);
	coeffs[2] = dot_product(co, co) - (sphere->radius * sphere->radius);
	d = (coeffs[1] * coeffs[1]) - (4 * coeffs[0] * coeffs[2]);
	if (d < 0)
		return (0);
	d = sqrt(d);
	coeffs[0] = 1 / (2.0 * coeffs[0]);
	t[0] = (-coeffs[1] + d) * coeffs[0];
	t[1] = (-coeffs[1] - d) * coeffs[0];
	if (t[0] <= 0 && t[1] <= 0)
		return (0);
	if (t[0] <= 0 || (t[1] > 0 && t[0] >= t[1]))
		t[0] = t[1];
	if (t[0] - EPSILON >= ray->collis.distance)
		return (0);
	if (mode == FAST)
		return (1);
	update_collision(ray, sphere, t[0] - EPSILON);
	return (1);
}
