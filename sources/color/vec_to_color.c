/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:23:10 by enoye             #+#    #+#             */
/*   Updated: 2022/08/09 18:08:14 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/color.h"

inline unsigned int	vec_to_color(t_color *pix)
{
	return ((((int)pix->r & 0xff) << 16) + (((int)pix->g & 0xff) << 8) \
													+ (((int)pix->b & 0xff)));
}
