/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:04:49 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 15:07:23 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

t_color	mix_colors(t_color koef, t_color base)
{
	base.r *= koef.r;
	base.g *= koef.g;
	base.b *= koef.b;
	return (base);
}
