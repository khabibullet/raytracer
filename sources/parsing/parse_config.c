/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:10 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/22 12:10:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../headers/parsing.h"
#include "../../headers/test.h"

void	parse_config(int argc, char **argv, t_minirt *rt)
{
	init_rays(rt);
	init_window_and_buffers(rt);
	init_cylinders(rt);
}
