/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:14:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 18:50:42 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/collision.h"

void	add_ambient_component(t_screen *screen, t_color	*ambient)
{
	int	i;
	int	j;

	i = 0;
	while (i < screen->heigth)
	{
		j = 0;
		while (j < screen->width)
		{
			if (screen->rays[i][j].collis.surface != NULL)
				screen->rays[i][j].color = mix_colors(\
					(t_color *)(screen->rays[i][j].collis.surface), *ambient);
			else
				screen->rays[i][j].color = (t_color){0, 0, 0};
			j++;
		}
		i++;
	}
}
