/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:58:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/22 21:26:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "minirt.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

# define KEY_Q		12
# define KEY_W		13
# define KEY_E		14
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_O		31
# define KEY_P		35
# define KEY_ESC	53
# define KEY_PLUS	24
# define KEY_MINUS	27

typedef struct s_rt
{
	int		key_pressed;
	int		mouse_moving;
	void	*mlx;
	void	*win;
}	t_rt;

int	key_press(int keycode, t_rt *rt);
int	key_release(int keycode, t_rt *rt);
int	exit_hook(t_rt *rt);
int	main_loop(t_rt *rt);
int	mouse_hook(int x2, int y2, t_rt *rt);

#endif