/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:15:19 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 18:00:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"
#include "../../libraries/libft/libft.h"

static int	parse_fov(char *line)
{
	char	*end;
	char	tmp;
	int		fov;

	end = line;
	while (*end != ' ' && *end != '\n' && *end != '\0')
		end++;
	tmp = *end;
	*end = '\0';
	fov = ft_atoi(line);
	*end = tmp;
	return (fov);
}

void	parse_camera(t_minirt *rt, char *line)
{
	line++;
	while (*line == ' ')
		line++;
	rt->scene.cam.coords = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.cam.direction = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.cam.fov = parse_fov(line);
}
