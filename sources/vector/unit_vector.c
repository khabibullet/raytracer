/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:19:18 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 13:17:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	unit_vector(t_vec vec)
{
	t_vec	unit_vec;
	float	vec_len;

	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
	{
		unit_vec.x = 0;
		unit_vec.y = 0;
		unit_vec.z = 0;
		return (unit_vec);
	}
	vec_len = vector_len(vec);
	unit_vec.x = vec.x / vec_len;
	unit_vec.y = vec.x / vec_len;
	unit_vec.z = vec.x / vec_len;
	return (unit_vec);
}
