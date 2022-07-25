/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:46:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/24 17:45:40 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

typedef struct s_minirt	t_minirt;

void	init_cylinders(t_minirt *rt);
void	init_window_and_buffers(t_minirt *rt);
void	init_rays(t_minirt *rt);
void	alloc_objects_arrays(t_minirt *rt);

#endif