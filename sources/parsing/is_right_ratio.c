/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_ratio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:43:48 by enoye             #+#    #+#             */
/*   Updated: 2022/07/05 13:13:30 by enoye            ###   ########.fr       */
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

int	is_right_ratio(char *line)
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