/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:07:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/27 19:49:01 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "minirt.h"
# include "screen.h"

void	test_collision(t_minirt *rt);
void	fill_buffer_color(t_img *buff, int w, int h, unsigned int color);

#endif