/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_hor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:46 by enoye             #+#    #+#             */
/*   Updated: 2022/06/25 19:30:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	find_normal_hor(t_vec vec)
{
	t_vec	var;

	var.x = vec.y;
	var.y = -vec.x;
	var.z = 0;
	return (var);
}
