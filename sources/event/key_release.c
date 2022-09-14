/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:16 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 22:19:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"

int	key_release(int keycode, t_minirt *rt)
{
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W || \
		keycode == KEY_S || keycode == KEY_E || keycode == KEY_Q || \
		keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_R || \
		keycode == KEY_ESC)
		rt->controls.motion--;
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
