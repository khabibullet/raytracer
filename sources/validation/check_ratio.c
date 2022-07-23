/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:43:48 by enoye             #+#    #+#             */
/*   Updated: 2022/07/23 17:45:04 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../libraries/libft/libft.h"

static void	is_valid_one(char *line)
{
	line++;
	if (*line == '.')
	{
		line++;
		if (*line != '0')
			exit_error();
		while (*line == '0')
			line++;
	}
	if (*line != ' ')
		exit_error();
}

void	check_ratio(char *line)
{
	if (*line != '0' && *line != '1')
		exit_error();
	while (*line == '0')
		line++;
	if (*line == '1')
		is_valid_one(line);
	else if (*line == '.')
	{
		line++;
		while (ft_isdigit(*line) == 1)
			line++;
		if (*line != ' ')
			exit_error();
	}
}
