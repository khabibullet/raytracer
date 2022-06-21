/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:07 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 15:43:16 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "minirt.h"

typedef struct s_pix
{
	float	x;
	float	y;
}	t_pix;

t_pix	find_pix_coords(int i, int j, float density, float ratio);

#endif