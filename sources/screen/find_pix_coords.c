/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:36:58 by enoye             #+#    #+#             */
/*   Updated: 2022/06/25 19:29:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

t_pix	find_pix_coords(int i, int j, float density, float ratio)
{
	t_pix	var;

	var.x = (2 * density * j) + density - 1;
	var.y = (2 * density * i) + density - ratio;
	return (var);
}
