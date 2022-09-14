/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:11:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 17:48:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

static inline int	optimal_root(float t[2], t_vec new[2], float *height, \
																	int *inside)
{
	int	checksum[2];

	*inside = 0;
	checksum[0] = 0;
	checksum[1] = 0;
	if (t[0] > 0 && fabsf(new[ORIGIN].z + new[COORDS].z * t[0]) < *height)
		checksum[0]++;
	if (t[1] > 0 && fabsf(new[ORIGIN].z + new[COORDS].z * t[1]) < *height)
		checksum[1]++;
	if (checksum[0] == 0 && checksum[1] == 0)
		return (0);
	if (checksum[1] == 0)
		*inside = 1;
	if (checksum[0] == 0 || (checksum[0] == checksum[1] && t[1] < t[0]))
		t[0] = t[1];
	return (1);
}

static inline void	transform_ray(t_vec new[2], t_cyl *cylinder, t_ray *ray)
{
	new[ORIGIN] = subtract_vecs(&ray->origin, &cylinder->center);
	new[ORIGIN] = matmul_mat_vec(cylinder->rot, &new[ORIGIN]);
	new[COORDS] = matmul_mat_vec(cylinder->rot, &ray->coords);
}

static void	update_collis(t_collision *collis, t_cyl *cylinder, \
													t_vec ray[2], int inside)
{
	t_vec	surf;

	collis->surface = (void *)cylinder;
	surf = vec_multiply_nbr(&ray[COORDS], collis->distance);
	surf = add_vecs(&ray[ORIGIN], &surf);
	surf.z = 0;
	collis->surf_normal = matmul_mat_vec(cylinder->rev, &surf);
	if (inside == 1)
	{
		collis->surf_normal.x = -collis->surf_normal.x;
		collis->surf_normal.y = -collis->surf_normal.y;
		collis->surf_normal.z = -collis->surf_normal.z;
	}
}

static inline float	find_discriminant(float *b, float *rr, float radius, \
																t_vec new[2])
{
	float	descriminant;

	*rr = new[COORDS].x * new[COORDS].x + new[COORDS].y * new[COORDS].y;
	*b = new[COORDS].x * new[ORIGIN].x + new[COORDS].y * new[ORIGIN].y;
	descriminant = *b * *b - *rr * (new[ORIGIN].x * \
			new[ORIGIN].x + new[ORIGIN].y * new[ORIGIN].y - radius * radius);
	return (descriminant);
}

int	collide_cylinder(t_ray *ray, t_cyl *cylinder, int mode)
{
	t_vec	new[2];
	float	d;
	float	rr;
	float	t[2];
	float	b;

	transform_ray(new, cylinder, ray);
	if (new[COORDS].x == 0 && new[COORDS].y == 0)
		return (0);
	d = find_discriminant(&b, &rr, cylinder->radius, new);
	if (d <= 0)
		return (0);
	d = sqrtf(d);
	rr = 1.0F / rr;
	t[0] = (-b + d) * rr;
	t[1] = (-b - d) * rr;
	if (!optimal_root(t, new, &cylinder->semi_heigth, (int *)&b) \
									|| t[0] - EPSILON > ray->collis.distance)
		return (0);
	if (mode == FULL)
	{
		ray->collis.distance = t[0] - EPSILON;
		update_collis(&ray->collis, cylinder, new, *(int *)&b);
	}
	return (1);
}
