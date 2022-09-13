/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:22:33 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 18:13:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

void	refresh_rays(t_ray **rays, int heigth, int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			rays[i][j].collis.surface = NULL;
			rays[i][j].collis.distance = 3.402823e+38;
			rays[i][j].color = (t_color){0.0F, 0.0F, 0.0F};
			rays[i][j].collis.surf_normal = (t_vec){0};
			rays[i][j].collis.surf_type = 0;
			++j;
		}
		++i;
	}
}
