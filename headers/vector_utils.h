/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:59:29 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/15 14:55:20 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILS_H
# define VECTOR_UTILS_H
# include "minirt.h"

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

float	vector_dot(t_vec vec1, t_vec vec2);

#endif