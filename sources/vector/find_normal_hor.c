/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_hor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:46 by enoye             #+#    #+#             */
/*   Updated: 2022/08/07 12:59:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline t_vec	find_normal_hor(t_vec *vec)
{
	t_vec	tmp;

	tmp = (t_vec){vec->y, -vec->x, 0};
	return (unit_vector(tmp));
}
