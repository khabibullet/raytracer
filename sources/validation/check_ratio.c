/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:43:48 by enoye             #+#    #+#             */
/*   Updated: 2022/07/22 22:26:19 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static int	if_alone(char **line)
{
	*line++;
	if (**line == '.')
	{
		*line++;
		if (**line != '0')
			return (0);
		while (**line == '0')
			*line++;
	}
	if (**line != ' ')
		return (0);
	return (1);
}

void	check_ratio(char *line)
{
	if (*line != '0' && *line != '1')
		return (0);
	while (*line == '0')
		line++;
	if (*line == '1')
	{
		if (if_alone(&line) == 0)
			return (0);
	}
	else if (*line == '.')
	{
		line++;
		if (ft_isdigit(*line) == 0)
			return (0);
		while (ft_isdigit(*line) == 1)
			line++;
		if (*line != ' ')
			return (0);
	}
	return (1);
}
