/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_datas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:31:21 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 18:08:18 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/utils.h"

static void	get_next_datas(t_minirt *rt, char *line, t_id *obj_id)
{
	if (*line == 'C')
		parse_camera(rt, line);
	else if (*line == 'A')
		parse_ambient(rt, line);
	else if (*line == 's' && *(line + 1) == 'p')
	{
		parse_sphere(rt, line, obj_id->sp_id);
		obj_id->sp_id++;
	}
	else if (*line == 'c' && *(line + 1) == 'y')
	{
		parse_cylinder(rt, line, obj_id->cy_id);
		obj_id->cy_id++;
	}
	else if (*line == 'p' && *(line + 1) == 'o')
	{
		parse_polygon(rt, line, obj_id->po_id);
		obj_id->po_id++;
	}
	else if (*line == 'p' && *(line + 1) == 'l')
	{
		parse_plane(rt, line, obj_id->pl_id);
		obj_id->pl_id++;
	}
	else if (*line == 'L')
	{
		parse_light(rt, line, obj_id->light_id);
		obj_id->light_id++;
	}
}

void	parse_obj_datas(t_minirt *rt, int fd)
{
	char	*line;
	t_id	obj_id;

	line = "kek";
	obj_id.sp_id = 0;
	obj_id.cy_id = 0;
	obj_id.pl_id = 0;
	obj_id.po_id = 0;
	obj_id.light_id = 0;
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			while (*line == ' ')
				line++;
			get_next_datas(rt, line, &obj_id);
		}
	}
}
