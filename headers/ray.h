/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/17 22:52:21 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "minirt.h"

typedef struct s_ray
{
	t_vec		coords;
	t_color		color;
	float		ratio;
}	t_ray;

#endif