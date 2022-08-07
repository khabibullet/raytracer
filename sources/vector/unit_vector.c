/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:19:18 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/07 12:49:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline t_vec	unit_vector(t_vec vec)
{
	float	norm;

	norm = 1.0F / vector_len(&vec);
	return ((t_vec){vec.x * norm, vec.y * norm, vec.z * norm});
}
