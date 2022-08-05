/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:36:17 by enoye             #+#    #+#             */
/*   Updated: 2022/08/05 13:55:51 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	vec_multiply_nbr(t_vec *vec, float nbr)
{
	return ((t_vec){vec->x * nbr, vec->x * nbr, vec->x * nbr});
}
