/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/25 21:40:42 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "screen.h"
# include "vector.h"
# include "color.h"

typedef struct s_ray
{
	t_vec		coords;
	t_vec		origin;
	float		ratio;
	t_color		color;
}	t_ray;

t_vec	get_cam_to_pix_vec(t_vec cam_dir, float focal, t_pix pix_coords);

#endif