/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:18:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 21:54:08 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../headers/vector.h"

inline float	vector_len(t_vec *vec)
{
	return (sqrtf(dot_product(*vec, *vec)));
}
