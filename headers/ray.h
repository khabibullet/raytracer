/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 17:22:50 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "minirt.h"

typedef struct s_ray
{
	t_vec		coords;
	t_vec		origin;
	t_color		color;
	float		ratio;
}	t_ray;

t_vec	get_cam_to_pix_vec(t_vec cam_dir, float focal, t_pix pix_coords);

#endif