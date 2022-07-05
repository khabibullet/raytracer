/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:19:18 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 14:11:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	unit_vector(t_vec vec)
{
	float	vec_len;

	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (vec);
	vec_len = 1.0F / vector_len(vec);
	vec.x *= vec_len;
	vec.y *= vec_len;
	vec.z *= vec_len;
	return (vec);
}
