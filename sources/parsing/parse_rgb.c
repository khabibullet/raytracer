/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:09:34 by enoye             #+#    #+#             */
/*   Updated: 2022/07/28 16:49:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

void	parse_rgb_object(char *line, t_color *color)
{
	char	**rgb;

	rgb = ft_split(line, ',');
	color->r = (float)safe_atoi(rgb[0]) / 255.0F;
	color->g = (float)safe_atoi(rgb[1]) / 255.0F;
	color->b = (float)safe_atoi(rgb[2]) / 255.0F;
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
}

void	parse_rgb_light(char *line, t_color *color, float ratio)
{
	char	**rgb;

	rgb = ft_split(line, ',');
	color->r = (float)safe_atoi(rgb[0]) * ratio;
	color->g = (float)safe_atoi(rgb[1]) * ratio;
	color->b = (float)safe_atoi(rgb[2]) * ratio;
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
}
