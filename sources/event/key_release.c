/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:16 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 22:21:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"

int	key_release(int keycode, t_minirt *rt)
{
	if (keycode == KEY_D)
		rt->controls.hor_shift--;
	else if (keycode == KEY_A)
		rt->controls.hor_shift++;
	else if (keycode == KEY_W)
		rt->controls.zoom--;
	else if (keycode == KEY_S)
		rt->controls.zoom++;
	else if (keycode == KEY_E)
		rt->controls.ver_shift--;
	else if (keycode == KEY_Q)
		rt->controls.ver_shift++;
	return (0);
}
