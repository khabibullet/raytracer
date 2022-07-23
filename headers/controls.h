/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:14:57 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 21:30:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define KEY_Q		12
# define KEY_W		13
# define KEY_E		14
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_O		31
# define KEY_R		15
# define KEY_ESC	53
# define KEY_PLUS	24
# define KEY_MINUS	27

typedef struct s_ctrl
{
	int		zoom;
	int		hor_shift;
	int		ver_shift;
	float	velocity;
}	t_ctrl;

#endif