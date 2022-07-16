/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_polygon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:23:35 by enoye             #+#    #+#             */
/*   Updated: 2022/07/16 15:46:01 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_polygon(t_minirt *rt, char *line, int obj_id)
{
	line = line + 2;
	while (*line == ' ')
		line++;
	rt->scene.polygones[obj_id].peak1 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygones[obj_id].peak2 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygones[obj_id].peak3 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygones[obj_id].color = parse_color(line);
}