/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:58:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 14:41:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

void	parse_rt(int argc, char **argv, t_minirt *rt);
void	init_window_and_buffers(t_minirt *rt);
void	count_objects(t_minirt *rt);
void	alloc_rays_array(t_minirt *rt);
void	alloc_objects_arrays(t_minirt *rt);
void	alloc_tmp_collisions_array(t_minirt *rt);
void	init_cylinders(t_minirt *rt);

#endif