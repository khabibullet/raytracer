/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:27:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 21:28:27 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

void	revert_rays(t_ray **rays, int heigth, int width)
{
	register int	i;
	register int	j;
	t_vec			tmp;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			tmp = rays[i][j].coords;
			tmp = vec_multiply_nbr(&tmp, rays[i][j].collis.distance);
			rays[i][j].origin = add_vecs(&rays[i][j].origin, &tmp);
			rays[i][j].beam = (t_vec){-tmp.x, -tmp.y, -tmp.z};
			rays[i][j].collis.surf_normal = unit_vector(\
												rays[i][j].collis.surf_normal);
			++j;
		}
		++i;
	}
}
