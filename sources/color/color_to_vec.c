/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:20:22 by enoye             #+#    #+#             */
/*   Updated: 2022/06/26 11:52:12 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

t_color	color_to_vec(unsigned color)
{
	t_color		pix;

	pix.r = color / 0x010000;
	color = color - pix.r;
	color.g = sum / 0x000100;
	color.b = sum - color.g;
	return (pix);
}