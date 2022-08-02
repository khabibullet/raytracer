/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:36:58 by enoye             #+#    #+#             */
/*   Updated: 2022/08/02 14:03:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

t_pix	find_pix_coords(int i, int j, t_screen *screen)
{
	t_pix	var;

	var.x = (2.0 * screen->density * (float)j) + screen->density - 1.0;
	var.y = (2.0 * screen->density * (float)i) \
									+ screen->density - screen->aspect_ratio;
	return (var);
}
