/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:51 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 12:34:43 by enoye            ###   ########.fr       */
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