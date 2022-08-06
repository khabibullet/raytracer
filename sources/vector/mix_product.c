/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:17:00 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 15:20:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline float	mix_product(t_vec *vec1, t_vec *vec2, t_vec *vec3)
{
	t_vec	tmp;

	tmp = cross_product(vec2, vec3);
	return (dot_product(vec1, &tmp));
}
