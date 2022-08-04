/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:51:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 18:13:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

/**
**	"Fast, Minimum Storage Ray-Triangle Intersection" algorithm
**	by Moller and Trumbore
**/

static void	init_basic(t_poly *poly, t_vec ab_ac[2], t_vec *n)
{
	ab_ac[0] = subtract_vecs(poly->peak2, poly->peak1);
	ab_ac[1] = subtract_vecs(poly->peak3, poly->peak1);
	*n = cross_product(ab_ac[0], ab_ac[1]);
}

int	collide_poly(t_ray *ray, t_poly *poly)
{
	t_vec	n;
	t_vec	ao;
	t_vec	ab_ac[2];
	float	t_u_v[3];
	float	denom;

	init_basic(poly, ab_ac, &n);
	denom = dot_product(ray->coords, n);
	if (denom == 0)
		return (0);
	denom = 1.0 / denom;
	ao = subtract_vecs(ray->origin, poly->peak1);
	t_u_v[0] = -denom * dot_product(ao, n);
	t_u_v[1] = denom * mix_product(ray->coords, ao, ab_ac[1]);
	t_u_v[2] = denom * mix_product(ray->coords, ab_ac[0], ao);
	if (t_u_v[0] <= 0 || t_u_v[1] < 0 || t_u_v[2] < 0
		|| (t_u_v[1] + t_u_v[2]) > 1.0)
		return (0);
	if (t_u_v[0] - EPSILON < ray->collis.distance)
	{
		ray->collis.surface = (void *)poly;
		ray->collis.distance = t_u_v[0] - EPSILON;
		ray->collis.surf_normal = (t_vec)n;
	}
	return (1);
}
