/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:59:17 by enoye             #+#    #+#             */
/*   Updated: 2022/07/12 13:26:16 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/utils.h"
#include "../../headers/minirt.h"

static void	plus_object(t_minirt *rt, char *line)
{
	while (*line == ' ')
		line++;
	if (*line == 'p' && *(line + 1) == 'l')
	{
		rt->scene.num_of.planes++;
		rt->scene.num_of.primitives++;
	}
	else if (*line == 'p' && *(line + 1) == 'o')
	{
		rt->scene.num_of.polygones++;
		rt->scene.num_of.primitives++;
	}
	else if (*line == 's' && *(line + 1) == 'p')
	{
		rt->scene.num_of.spheres++;
		rt->scene.num_of.primitives++;
	}
	else if (*line == 'c' && *(line + 1) == 'y')
	{
		rt->scene.num_of.cylinders++;
		rt->scene.num_of.primitives++;
	}
	else if (*line == 'L')
		rt->scene.num_of.lights++;
}

void	parse_objects_num(t_minirt *rt, int fd)
{
	char	*line;

	line = "kek";
	rt->scene.num_of.polygones = 0;
	rt->scene.num_of.spheres = 0;
	rt->scene.num_of.cylinders = 0;
	rt->scene.num_of.planes = 0;
	rt->scene.num_of.lights = 0;
	rt->scene.num_of.primitives = 0;
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			plus_object(rt, line);
			free(line);
		}
	}
}