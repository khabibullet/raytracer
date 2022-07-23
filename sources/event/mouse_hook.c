/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:49:40 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 22:22:05 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"

int	mouse_hook(int x2, int y2, t_minirt *rt)
{
	(void)x2;
	(void)y2;
	(void)rt;
	// static int	flag;
	// static int	x1;
	// static int	y1;


	// if (flag)
	// {
	// 	gen->angles[0] += ((float)(x1 - x2)) * gen->mouse_sens;
	// 	gen->angles[1] += ((float)(y1 - y2)) * gen->mouse_sens;
	// 	if (gen->angles[0] > 360)
	// 		gen->angles[0] -= 360;
	// 	else if (gen->angles[0] < -360)
	// 		gen->angles[0] += 360;
	// 	if (gen->angles[1] > 360)
	// 		gen->angles[1] -= 360;
	// 	else if (gen->angles[1] < -360)
	// 		gen->angles[1] += 360;
	// }
	// x1 = x2;
	// y1 = y2;
	// flag = 1;
	return (0);
}
