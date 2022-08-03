/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:11:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/03 22:33:46 by anemesis         ###   ########.fr       */
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

static void	transform_ray(t_vec new[2], t_cyl *cylinder, t_ray *ray)
{
	new[ORIGIN] = subtract_vecs(ray->origin, cylinder->center);
	new[ORIGIN] = matmul_mat_vec(cylinder->rot, &new[ORIGIN]);
	new[COORDS] = matmul_mat_vec(cylinder->rot, &ray->coords);
}

int	collide_cylinder(t_ray *ray, t_cyl *cylinder)
{
	t_vec	new[2];
	float	d;
	float	rr;
	float	t[2];
	float	b;

	transform_ray(new, cylinder, ray);
	rr = new[COORDS].x * new[COORDS].x + new[COORDS].y * new[COORDS].y;
	b = new[COORDS].x * new[ORIGIN].x + new[COORDS].y * new[ORIGIN].y;
	d = b * b - rr * (new[ORIGIN].x * new[ORIGIN].x + new[ORIGIN].y \
						* new[ORIGIN].y - cylinder->radius * cylinder->radius);
	if (d <= 0 || (new[COORDS].x == 0 && new[COORDS].y == 0))
		return (0);
	d = sqrtf(d);
	rr = 1.0F / rr;
	t[0] = (-b + d) * rr;
	t[1] = (-b - d) * rr;
	if (!optimal_root(t, &new[ORIGIN], &new[COORDS], &cylinder->semi_heigth))
		return (0);
	if (t[0] - EPSILON > ray->collis.distance)
		return (0);
	ray->collis.surface = (void *)cylinder;
	ray->collis.distance = t[0] - EPSILON;
	return (1);
}
