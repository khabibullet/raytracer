/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors_to_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:52:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/24 18:13:07 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/minirt.h"

void	put_colors_to_back_buff(t_minirt *rt)
{
	int		i;
	int		j;
	// t_ray	*ray;

	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			// get_surf_normal();
			j++;
		}
		i++;
	}
}
