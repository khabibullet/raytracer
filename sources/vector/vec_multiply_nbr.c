/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:36:17 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 17:56:50 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	vec_multiply_len(t_vec vec, float nbr)
{
	vec.x = vec.x * nbr;
	vec.y = vec.y * nbr;
	vec.z = vec.z * nbr;
	return (vec);
}