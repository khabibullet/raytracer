/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:10:55 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"
#include <math.h>

t_color	add_colors(t_color col1, t_color col2)
{
	col2.r = fminf(col2.r + col1.r, 255.0F);
	col2.g = fminf(col2.g + col1.g, 255.0F);
	col2.b = fminf(col2.b + col1.b, 255.0F);
	return (col2);
}
