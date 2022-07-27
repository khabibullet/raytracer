/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:32:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/27 22:44:12 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "../../headers/validation.h"
#include "../../headers/utils.h"

static void	count_elements(char *line, int *ambient, int *cam, t_num *num_of)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "A ", 2))
		(*ambient)++;
	else if (!ft_strncmp(line, "C ", 2))
		(*cam)++;
	else if (!ft_strncmp(line, "L ", 2))
		num_of->lights++;
	else if (!ft_strncmp(line, "sp ", 3))
		num_of->spheres++;
	else if (!ft_strncmp(line, "pl ", 3))
		num_of->planes++;
	else if (!ft_strncmp(line, "cy ", 3))
		num_of->cylinders++;
	else if (!ft_strncmp(line, "po ", 3))
		num_of->polygons++;
	else
		return ;
}

static void	check_num_of_elements(char *filename, t_num *num_of)
{
	char		*line;
	int			fd;
	int			ambient_num;
	int			camera_num;

	ambient_num = 0;
	camera_num = 0;
	*num_of = (t_num){0};
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		count_elements(line, &ambient_num, &camera_num, num_of);
		free(line);
		line = get_next_line(fd);
	}
	num_of->primitives = num_of->planes + num_of->spheres + \
							num_of->cylinders + num_of->polygons;
	if (camera_num != 1 || num_of->primitives == 0)
		exit_error();
	if (num_of->lights != 1 || ambient_num != 1)
		exit_error();
	close(fd);
}

static void	validate_line(char *line)
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
		valid_ambient(line + 1);
	else if (!ft_strncmp(line, "C ", 2))
		valid_camera(line + 1);
	else if (!ft_strncmp(line, "L ", 2))
		valid_light(line + 1);
	// else if (!ft_strncmp(line, "sp ", 3))
	// 	valid_sphere(line + 2);
	// else if (!ft_strncmp(line, "pl ", 3))
	// 	valid_plane(line + 2);
	// else if (!ft_strncmp(line, "cy ", 3))
	// 	valid_cylinder(line + 2);
	// else if (!ft_strncmp(line, "po ", 3))
	// 	valid_polygon(line + 2);
	else
		return ;
}

static void	validate_file(char *filename)
{
	int		fd;

	if (ft_strlen(filename) < 3)
		exit_error();
	if (ft_strcmp(filename + ft_strlen(filename) - 3, ".rt"))
		exit_error();
	if (open(filename, O_DIRECTORY) > 0)
		exit_error();
	fd = open(filename, O_RDONLY);
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
	while (line != NULL)
	{
		validate_line(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
