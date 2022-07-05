/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:10:55 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 15:11:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

t_color	add_colors(t_color col1, t_color col2)
{
	col2.r += col1.r;
	col2.g += col1.g;
	col2.b += col1.b;
	return (col2);
}
