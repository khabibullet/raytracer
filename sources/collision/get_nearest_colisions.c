/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_colisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:26:38 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/12 20:04:14 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	get_first_collisions(t_ray **ray, t_scene *scene, int heigth, int width)
{
	register int	i;
	register int	j;
	// t_color			color;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			current_ray_nearest_collision(&ray[i][j], scene, FULL, i, j);
			// if (i == 10 && j == 10)
			// {
			// 	// color = *(t_color *)&ray[i][j].collis.surface
			// 	printf("%p\n", ray[i][j].collis.surface);
			// }
			++j;
		}
		++i;
	}
}
