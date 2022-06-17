/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:19:18 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/17 22:54:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	unit_vector(t_vec vec)
{
	t_vec	unit_vec;
	float	vec_len;

	vec_len = vector_len(vec);
	unit_vec.x = vec.x / vec_len;
	unit_vec.y = vec.x / vec_len;
	unit_vec.z = vec.x / vec_len;
	return (unit_vec);
}
