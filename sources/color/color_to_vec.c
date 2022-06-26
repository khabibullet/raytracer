/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:20:22 by enoye             #+#    #+#             */
/*   Updated: 2022/06/26 11:35:48 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

t_color	color_to_vec(unsigned color)
{
	t_color		pix;

	pix.b = color % 0x100;
	color = color / 0x100;
	pix.g = color % 0x100;
	color = color / 0x100;
	pix.r = color % 0x100;
	return (pix);
}