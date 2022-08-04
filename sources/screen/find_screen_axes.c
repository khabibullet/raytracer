/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_screen_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:07:08 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 21:11:01 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

void	find_screen_axes(t_screen *screen, t_cam *cam)
{
	screen->hor_axis = unit_vector(find_normal_hor(&cam->direction));
	screen->ver_axis = unit_vector(find_normal_ver(&cam->direction));
}
