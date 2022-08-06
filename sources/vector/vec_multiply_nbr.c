/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:36:17 by enoye             #+#    #+#             */
/*   Updated: 2022/08/05 18:16:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline t_vec	vec_multiply_nbr(t_vec *vec, float nbr)
{
	return ((t_vec){vec->x * nbr, vec->y * nbr, vec->z * nbr});
}
