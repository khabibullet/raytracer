/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:36:58 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 12:46:04 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_pix	find_pix_coords(int i, int j, float density, float ratio)
{
	t_pix	var;

	var.x = (2 * d * j) + density - 1;
	var.y = (2 * d * i) + density - ratio;
	return (var);
}
