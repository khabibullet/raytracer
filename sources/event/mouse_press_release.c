/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:16:23 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 20:58:27 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/event.h"

int	mouse_press(int button, int x, int y, t_minirt *rt)
{
	(void)x;
	(void)y;
	mlx_mouse_hide();
	if (button == 1)
		rt->controls.mouse_press = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_minirt *rt)
{
	(void)x;
	(void)y;
	mlx_mouse_show();
	if (button == 1)
		rt->controls.mouse_press = 0;
	return (0);
}
