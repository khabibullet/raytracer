/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:16:23 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 18:01:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/event.h"

int	mouse_press(int button, int x, int y, t_minirt *rt)
{
	(void)x;
	rt->controls.motion++;
	if (y <= 1)
		return (0);
	mlx_mouse_hide();
	if (button == 1)
		rt->controls.mouse_press = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_minirt *rt)
{
	(void)x;
	(void)y;
	rt->controls.motion--;
	mlx_mouse_show();
	if (button == 1)
		rt->controls.mouse_press = 0;
	return (0);
}
