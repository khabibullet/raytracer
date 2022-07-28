/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:44:37 by enoye             #+#    #+#             */
/*   Updated: 2022/07/28 17:32:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

void	parse_ambient(char *line, t_scene *scene)
{
	char	**params;

	params = ft_split(line, ' ');
	parse_rgb_light(params[1], &scene->ambient, ft_atof(params[0]));
	free(params[0]);
	free(params[1]);
	free(params);
}
