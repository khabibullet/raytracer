/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_primitives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:50:34 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/29 15:20:17 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/scene.h"

void	put_test_primitives(t_minirt *rt)
{
	rt->scene.planes[0] = (t_plane){0, {100, 100, 100}, {10, 0, -20}, \
																	{0, 0, 1}};
	rt->scene.planes[1] = (t_plane){0, {100, 100, 100}, {10, 0, 20}, \
																	{0, 0, 1}};
	rt->scene.polygons[0] = (t_poly){0, {200, 100, 0}, {5, 10, -3}, {5, 3, -3}, \
																{7, 7, 3}};
	rt->scene.polygons[1] = (t_poly){0, {100, 200, 0}, {3, 8, -6}, {3, 3, -8}, \
																{3, 5, 1}};
	rt->scene.spheres[0] = (t_sphere){0, {0, 200, 200}, {0, 0, 0}, 1.1};
	rt->scene.spheres[1] = (t_sphere){0, {0, 50, 200}, {0, 0, 0}, 1.1};
}
