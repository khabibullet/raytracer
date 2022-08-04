/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:22:33 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 23:08:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

void	refresh_rays(t_minirt *rt)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			rt->screen.rays[i][j].collis.surface = NULL;
			rt->screen.rays[i][j].collis.distance = 3.402823e+38;
			rt->screen.rays[i][j].color = (t_color){0.0F, 0.0F, 0.0F};
			++j;
		}
		++i;
	}
}
