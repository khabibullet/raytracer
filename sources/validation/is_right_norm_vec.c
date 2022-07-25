/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_norm_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:09:30 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 18:25:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static int	if_dot(char **line, int k)
{
	line++;
	if (ft_isdigit(**line) == 0)
		return (0);
	while (ft_isdigit(**line) == 1)
		line++;
	if (k == 2 && **line == ' ') // v konce probel
		return (1);
	else if (k !=2 && **line == ',') // esli ne konec, to zapyataya posle chisla
		line++;
	else
		return (0);
	return (0);
}

static int	if_alone(char **line, int k)
{
	(*line)++;
	if (**line == '.')
	{
		(*line)++;
		if (**line != '0')
			return (0);
		while (**line == '0')
			(*line)++;
	}
	if (k == 2 && **line == ' ') // v konce probel
		return (1);
	else if (k !=2 && **line == ',') // esli ne konec, to zapyataya posle chisla
		(*line)++;
	else
		return (0);
	return (10);
}



static int	what_next(char **line, int k)
{
	int	res;

	if (**line == '1')
	{
		res = if_alone(line, k);
		if (res == 0)
			return (0);
		else if (res == 1)
			return (1);
	}
	else if (**line == '.')
	{
		res = if_dot(line, k);
		if (res == 0)
			return (0);
		else if (res == 1)
			return (1);
	}
	return (10);
}

static int	circle(char **line, int k)
{
	int	res;

	if (**line == '-')
		line++;
	if (**line != '0' && **line != '1')
		return (0);
	while (**line == '0')
		(*line)++;
	if (**line == '1' || **line == '.')
	{
		res = what_next(line, k);
		if (res == 0)
			return (0);
		else if (res == 1)
			return (1);
	}
	else if (k == 2 && **line == ' ') // v konce probel
		return (1);
	else if (k !=2 && **line == ',') // esli ne konec, to zapyataya posle chisla
		(*line)++;
	else
		return (0);
	return (10);
}

int	is_right_norm_vec(char *line)
{
	int	k;
	int	res;

	k = 0;
	while (k < 3)
	{
		res = circle(&line, k);
		if (res == 0)
			return (0);
		else if (res == 1)
			return (1);
		k++;
	}
	return (1);
}
