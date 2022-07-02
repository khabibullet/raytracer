/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:36:58 by enoye             #+#    #+#             */
/*   Updated: 2022/06/28 12:22:32 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

t_pix	find_pix_coords(int i, int j, float density, float ratio)
{
	t_pix	var;

	var.x = (2.0 * density * (float)j) + density - 1.0;
	var.y = (2.0 * density * (float)i) + density - ratio;
	return (var);
}
