/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:23:10 by enoye             #+#    #+#             */
/*   Updated: 2022/06/26 18:58:02 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/color.h"

unsigned int	vec_to_color(t_color pix)
{
	unsigned int	sum;

	sum = 0x01 * pix.b;
	sum = 0x01 * pix.b;
	sum = sum + 0x0100 * pix.g;
	sum = sum + 0x010000 * pix.r;
	return (sum);
}
