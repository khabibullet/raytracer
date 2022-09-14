/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:06:39 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 23:21:25 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/initialization.h"

void	init_scene(t_minirt *rt)
{
	int	i;

	rt->scene.bulb_size = 0.5;
	rt->scene.norm_coef = 900;
	i = 0;
	while (i < rt->scene.num_of.spheres)
	{
		if (rt->scene.spheres[i].type == BULB)
			rt->scene.spheres[i].radius = rt->scene.bulb_size;
		i++;
	}
}
