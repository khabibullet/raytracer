/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:55:26 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/28 16:25:40 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../headers/validation.h"

static void	check_components_all_digit(char **rgb)
{
	char	*color;

	while (*rgb)
	{
		color = *rgb;
		while (*color)
		{
			if (!ft_isdigit(*color))
				exit_error();
			color++;
		}
		rgb++;
	}
}

static void	check_components_limit(char **rgb)
{
	char	*color;

	while (*rgb)
	{
		color = *rgb;
		while (*color == '0')
			color++;
		if (ft_strlen(color) > 3 || ft_atoi(color) > 255)
			exit_error();
		rgb++;
	}
}

void	check_rgb(char *line)
{
	char	**rgb;

	check_num_of_char(line, ',', 2);
	rgb = ft_split(line, ',');
	check_num_of_fields(rgb, 3);
	check_components_all_digit(rgb);
	check_components_limit(rgb);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
}
