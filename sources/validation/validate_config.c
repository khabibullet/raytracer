/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:32:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/22 22:07:16 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"
#include "../../headers/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

static void	count_elements(char *line, t_elements *elements, t_num *num_of)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "A ", 2))
		elements->ambient++;
	else if (ft_strncmp(line, "C ", 2))
		elements->camera++;
	else if (ft_strncmp(line, "L ", 2))
		num_of->lights++;
	else if (ft_strncmp(line, "sp ", 3))
		num_of->spheres++;
	else if (ft_strncmp(line, "pl ", 3))
		num_of->planes++;
	else if (ft_strncmp(line, "cy ", 3))
		num_of->cylinders++;
	else if (ft_strncmp(line, "po ", 3))
		num_of->polygons++;
}

static void	check_num_of_elements(char *filename, t_num *num_of)
{
	char		*line;
	int			fd;
	t_elements	elements;

	elements = (t_elements){0};
	*num_of = (t_num){0};
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		count_elements(line, &elements, num_of);
		free(line);
		line = get_next_line(fd);
	}
	num_of->primitives = num_of->planes + num_of->spheres + \
							num_of->cylinders + num_of->polygons;
	if (elements.camera != 1 || num_of->primitives == 0)
		exit_error();
	if (num_of->lights != 1 || elements.ambient != 1)
		exit_error();
	close(fd);
}

static void	validate_line(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strcmp(line, "\n"))
		return ;
	if (ft_strncmp(line, "A ", 2))
		valid_ambient(line + 1);
	else if (ft_strncmp(line, "C ", 2))
		valid_camera(line + 1);
	else if (ft_strncmp(line, "L ", 2))
		valid_light(line + 1);
	else if (ft_strncmp(line, "sp ", 3))
		valid_sphere(line + 2);
	else if (ft_strncmp(line, "pl ", 3))
		valid_plane(line + 2);
	else if (ft_strncmp(line, "cy ", 3))
		valid_cylinder(line + 2);
	else if (ft_strncmp(line, "po ", 3))
		valid_polygon(line + 2);
	else
		return ;
}

static void	validate_file(char *name)
{
	int		fd;

	if (ft_strlen(name) < 3)
		exit_error();
	if (!ft_strcmp(name + ft_strlen(name) - 3, ".rt"))
		exit_error();
	if (open(name, O_DIRECTORY) > 0)
		exit_error();
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit_error();
	else
		close(fd);
}

void	validate_config(int argc, char *filename, t_num *num_of)
{
	int		fd;
	char	*line;

	if (argc != 2)
		exit_error();
	validate_file(filename);
	check_num_of_elements(filename, num_of);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		validate_line(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
