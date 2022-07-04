/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:20:22 by enoye             #+#    #+#             */
/*   Updated: 2022/07/02 20:50:33 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

t_color	color_to_vec(unsigned int color)
{
	t_color		pix;

	pix.r = color / 0x010000;
	color = color - pix.r;
	pix.g = color / 0x000100;
	pix.b = color - pix.g;
	return (pix);
}
