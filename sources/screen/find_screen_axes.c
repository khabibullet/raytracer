/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_screen_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:07:08 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/07 13:03:53 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

inline void	find_screen_axes(t_screen *screen, t_vec *direction)
{
	screen->hor_axis = find_normal_hor(direction);
	screen->ver_axis = find_normal_ver(direction);
}
