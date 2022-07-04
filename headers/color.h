/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:51 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 20:51:25 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

t_color			color_to_vec(unsigned int color);
unsigned int	vec_to_color(t_color pix);
void			limit_color(t_color *color);

#endif