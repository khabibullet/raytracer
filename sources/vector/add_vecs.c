/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vecs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:16:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 15:19:24 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline t_vec	add_vecs(t_vec *vec1, t_vec *vec2)
{
	return ((t_vec){vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z});
}
