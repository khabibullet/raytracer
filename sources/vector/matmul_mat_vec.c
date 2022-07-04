/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matmul_mat_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:42:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 18:47:47 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	matmul_mat_vec(float mat[3][3], t_vec *vec)
{
	t_vec	res;

	res.x = mat[0][0] * vec->x + mat[0][1] * vec->y + mat[0][2] * vec->z;
	res.y = mat[1][0] * vec->x + mat[1][1] * vec->y + mat[1][2] * vec->z;
	res.z = mat[2][0] * vec->x + mat[2][1] * vec->y + mat[2][2] * vec->z;

	return (res);
}
