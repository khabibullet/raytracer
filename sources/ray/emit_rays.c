/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:30:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 20:09:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	emit_rays(t_screen *screen, t_cam *cam, int heigth, int width)
{
	register int	j;
	register int	i;
	t_vec			tmp;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			tmp = cam_to_pix_vec(cam, &screen->pixels[i][j], screen);
			screen->rays[i][j].origin = add_vecs(&cam->coords, &tmp);
			screen->rays[i][j].coords = unit_vector(tmp);
			++j;
		}
		++i;
	}
}
