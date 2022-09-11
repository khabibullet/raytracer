/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:23:10 by enoye             #+#    #+#             */
/*   Updated: 2022/09/11 19:39:06 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

inline unsigned int	vec_to_color(t_color *pix)
{
	unsigned int	pixel;

	pixel = 0;
	if (pix->r < 255)
		pixel += ((int)pix->r & 0xff) << 16;
	else
		pixel += 0xff0000;
	if (pix->g < 255)
		pixel += ((int)pix->g & 0xff) << 8;
	else
		pixel += 0xff00;
	if (pix->b < 255)
		pixel += (int)pix->b & 0xff;
	else
		pixel += 0xff;
	return (pixel);
}
