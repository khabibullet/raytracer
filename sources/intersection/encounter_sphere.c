/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encounter_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:19:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 22:38:47 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	encounter_sphere(t_ray ray, t_sphere sphere)
{
	t_vec	intersec;
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
		intersec.x = NAN;
		return (intersec);
	}
	t1 = (-b + sqrtf(d)) / 2 / a;
	t2 = (-b - sqrtf(d)) / 2 / a;

	if (t1 < 0 && t2 < 0)
	{
		intersec.x = NAN;
		return (intersec);
	}
	else if (t1 < 0)
		t1 = t2;
	else if (t2 < 0)
		t2 = t1;
	else
		t1 = t1 < t2 ? t1 : t2;
	intersec = add_vecs(ray.coords, vec_multiply_nbr(ray.origin, t1));
	return (intersec);
}
