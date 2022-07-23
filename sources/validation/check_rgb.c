/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:55:26 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 17:47:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../libraries/libft/libft.h"

static void	check_num_of_components(char **split)
{
	int	count;

	count = 0;
	while (*split)
	{
		split++;
		count++;
	}
	if (count != 3)
		exit_error();
}

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

static void	check_num_of_commas(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
		{
			if (++count > 2)
				exit_error();
		}
		str++;
	}
}

void	check_rgb(char *line)
{
	char	*color_vec;
	char	**rgb;

	check_num_of_commas(line);
	color_vec = ft_strtrim(line, " \n");
	rgb = ft_split(color_vec, ',');
	check_num_of_components(rgb);
	check_components_all_digit(rgb);
	check_components_limit(rgb);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(color_vec);
}
