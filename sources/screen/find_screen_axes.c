/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_screen_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:07:08 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 14:11:07 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

void	find_screen_axes(t_screen *screen, t_vec *direction)
{
	t_vec	tmp;

	tmp = find_normal_hor(direction);
	screen->hor_axis = unit_vector(&tmp);
	tmp = find_normal_ver(direction);
	screen->ver_axis = unit_vector(&tmp);
}
