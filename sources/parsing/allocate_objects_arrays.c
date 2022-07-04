/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_objects_arrays.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:39 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 21:04:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"

void	alloc_objects_arrays(t_minirt *rt)
{
	rt->scene.spheres = malloc(sizeof(*rt->scene.spheres) \
											* rt->scene.num_of.spheres);
	rt->scene.planes = malloc(sizeof(*rt->scene.planes) \
											* rt->scene.num_of.planes);
	rt->scene.cylinders = malloc(sizeof(*rt->scene.cylinders) \
											* rt->scene.num_of.cylinders);
	rt->scene.polygons = malloc(sizeof(*rt->scene.polygons) \
											* rt->scene.num_of.polygons);
	rt->scene.lights = malloc(sizeof(*rt->scene.lights) \
											* rt->scene.num_of.lights);
}
