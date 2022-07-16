/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:57:03 by enoye             #+#    #+#             */
/*   Updated: 2022/07/16 15:53:41 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_plane(t_minirt *rt, char *line, int obj_id)
{
	line = line + 2;
	while (*line == ' ')
		line++;
	rt->scene.planes[obj_id].coords = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++
	rt->scene.planes[obj_id].normal = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++
	rt->scene.planes[obj_id].color = parse_color(line);
}