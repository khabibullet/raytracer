/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:19:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/26 18:06:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../headers/ray.h"
#include "../../headers/scene.h"
#include "../../headers/vector.h"

t_vec	collide_sphere(t_ray ray, t_sphere sphere)
{
	t_vec	collision;
	float	a;
	float	b;
	float	c;
	float	d;
	float	t1;
	float	t2;
	t_vec	sub;

	sub = subtract_vecs(ray.origin, sphere.center);
	a = dot_product(ray.coords, ray.coords);
	b = 2 * dot_product(ray.coords, sub);
	c = vector_len(sub) - (sphere.radius * sphere.radius);
	d = (b * b) - (4 * a * c);
	if (d < 0)
	{
		collision.x = NAN;
		return (collision);
	}
	t1 = (-b + sqrtf(d)) / 2 / a;
	t2 = (-b - sqrtf(d)) / 2 / a;

	if (t1 < 0 && t2 < 0)
	{
		collision.x = NAN;
		return (collision);
	}
	else if (t1 < 0)
		t1 = t2;
	else if (t2 < 0)
		t2 = t1;
	else
		t1 = t1 < t2 ? t1 : t2;
	collision = add_vecs(ray.coords, vec_multiply_nbr(ray.origin, t1));
	return (collision);
}
