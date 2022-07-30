/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:55:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/30 19:05:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

static void	parse_line(char *line, t_minirt *rt)
{
	char	*newline;

	while (*line == ' ')
		line++;
	if (!ft_strcmp(line, "\n"))
		return ;
	newline = ft_strchr(line, '\n');
	if (newline)
		*newline = '\0';
	if (!ft_strncmp(line, "A ", 2))
		parse_ambient(line + 1, &rt->scene);
	else if (!ft_strncmp(line, "C ", 2))
		parse_camera(line + 1, &rt->scene);
	else if (!ft_strncmp(line, "L ", 2))
		parse_light(line + 1, &rt->scene);
	else if (!ft_strncmp(line, "sp ", 3))
		parse_sphere(line + 2, &rt->scene);
	else if (!ft_strncmp(line, "pl ", 3))
		parse_plane(line + 2, &rt->scene);
	else if (!ft_strncmp(line, "cy ", 3))
		parse_cylinder(line + 2, &rt->scene);
	else if (!ft_strncmp(line, "po ", 3))
		parse_polygon(line + 2, &rt->scene);
	else
		return ;
}

void	parse_config(char *filename, t_minirt *rt)
{
	int		fd;
	char	*line;

	alloc_objects_arrays(rt);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		parse_line(line, rt);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
