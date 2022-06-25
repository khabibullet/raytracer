/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:36:17 by enoye             #+#    #+#             */
/*   Updated: 2022/06/25 19:31:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	vec_multiply_nbr(t_vec vec, float nbr)
{
	vec.x = vec.x * nbr;
	vec.y = vec.y * nbr;
	vec.z = vec.z * nbr;
	return (vec);
}
