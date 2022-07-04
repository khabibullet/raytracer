/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:11:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 11:55:10 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/scene.h"
#include "../../headers/ray.h"
#include "../../headers/vector.h"

int	collide_cylinder(t_ray *ray, t_cyl *cylinder)
{
	t_vec	vec;
	t_vec	origin;
	float	d;
	float	rr;
	float	t[2];

	origin = subtract_vecs(ray->origin, cylinder->center);
	origin = matmul_mat_vec(cylinder->rot, &origin);
	vec = matmul_mat_vec(cylinder->rot, &ray->coords);
	rr = vec.x * vec.x + vec.y * vec.y;
	d = vec.x + vec.y;
	d = d * d - rr * origin.x * (origin.x + origin.y * origin.y + \
										cylinder->radius * cylinder->radius);
	if (d < 0)
		return (0);
	d = sqrtf(d);
	rr = 1.0F / rr;
	t[0] = (-vec.x - vec.y + d) * rr;
	t[1] = (-vec.x - vec.y - d) * rr;
	
}
