/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:58:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 16:40:50 by enoye            ###   ########.fr       */
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

#endif