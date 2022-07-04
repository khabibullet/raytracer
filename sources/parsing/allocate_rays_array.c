/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_rays_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:22:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 21:05:22 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"

void	alloc_rays_array(t_minirt *rt)
{
	int	i;

	i = 0;
	rt->screen.rays = malloc(sizeof(*rt->screen.rays) * rt->screen.heigth);
	while (i < rt->screen.heigth)
	{
		rt->screen.rays[i] = malloc(sizeof(**rt->screen.rays) \
															* rt->screen.width);
		i++;
	}
}
