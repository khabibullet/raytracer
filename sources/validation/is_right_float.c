/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:27:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/22 21:53:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

int	is_right_float(char *line)
{
	if (ft_isdigit(*line) == 0)
		return (0);
	while (ft_isdigit(*line) == 1)
		line++;
	if (*line != ' ' && *line != '.')
		return (0);
	if (*line == ' ')
		return (1);
	else if (*line == '.')
	{
		line++;
		if (ft_isdigit(*line) == 0)
			return (0);
		while (ft_isdigit(*line) == 1)
			line++;
		if (*line == ' ')
			return (1);
	}
	return (0);
}
