/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_colisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:26:38 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 15:59:04 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	get_nearest_collisions(t_ray **ray, t_scene *sc, int heigth, int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			current_ray_nearest_collision(&ray[i][j], sc);
			++j;
		}
		++i;
	}
}
