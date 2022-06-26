/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:17:00 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/26 17:42:58 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

float	mix_product(t_vec vec1, t_vec vec2, t_vec vec3)
{
	return (dot_product(vec1, cross_product(vec2, vec3)));
}
