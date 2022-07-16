/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:04:49 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/16 15:14:01 by enoye            ###   ########.fr       */
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
