/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:11:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 17:35:17 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

static int	optimal_root(float t[2], t_vec *origin, t_vec *coords, float *heigh)
{
	int	checksum[2];

	checksum[0] = 0;
	checksum[1] = 0;
	if (t[0] > 0 && fabsf(origin->z + coords->z * t[0]) < *heigh)
		checksum[0]++;
	if (t[1] > 0 && fabsf(origin->z + coords->z * t[1]) < *heigh)
		checksum[1]++;
	if (checksum[0] == 0 && checksum[1] == 0)
		return (0);
	if (checksum[0] == 0 || (checksum[0] == checksum[1] && t[1] < t[0]))
		t[0] = t[1];
	return (1);
}

int	collide_cylinder(t_ray *ray, t_cyl *cylinder)
{
	t_vec	new_coords;
	t_vec	new_origin;
	float	d;
	float	rr;
	float	t[2];

	new_origin = subtract_vecs(ray->origin, cylinder->center);
	new_origin = matmul_mat_vec(cylinder->rot, &new_origin);
	new_coords = matmul_mat_vec(cylinder->rot, &ray->coords);
	rr = new_coords.x * new_coords.x + new_coords.y * new_coords.y;
	d = new_coords.x + new_coords.y;
	d = d * d - rr * new_origin.x * (new_origin.x + new_origin.y \
						* new_origin.y + cylinder->radius * cylinder->radius);
	if (d <= 0 || (new_coords.x == 0 && new_coords.y == 0))
		return (0);
	d = sqrtf(d);
	rr = 1.0F / rr;
	t[0] = (-new_coords.x - new_coords.y + d) * rr;
	t[1] = (-new_coords.x - new_coords.y - d) * rr;
	if (!optimal_root(t, &new_origin, &new_coords, &cylinder->semi_heigth) \
									|| t[0] - EPSILON < ray->collis.distance)
		return (0);
	ray->collis.surface = (void *)cylinder;
	ray->collis.distance = t[0] - EPSILON;
	return (1);
}
