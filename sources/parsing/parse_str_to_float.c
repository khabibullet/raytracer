/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_to_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:21:42 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 12:34:30 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"
#include <math.h>

static float	if_dot_here(char *str, char *end, int before, float sum)
{
	int	after;
	int	len;

	*end == '\0';
	before = ft_atoi(str);
	*end = '.';
	end++;
	len = 0;
	while (*end == '0')
	{
		len++;
		end++;
	}
	if (*end == '\0')
	{
		sum = (float) before;
		return (sum);
	}
	str = end;
	while (*end != '\0')
	{
		len++;
		end++;
	}
	after = ft_atoi(str);
	len = len + ft_strlen(str);
	sum = (float) before + (float) after / pow(10, len);
	return (sum);
}

float	parse_str_to_float(char *str)
{
	int		before;
	float	sum;
	char	*end;

	end = str;
	before = 0;
	sum = 0;
	while (*end != '\0' && *end != '.')
		end++;
	if (*end == '\0')
	{
		before = ft_atoi(str);
		sum = (float) before;
		return (sum);
	}
	if (*end == '.')
		sum = if_dot_here(str, end, before, sum);
	return (sum);
}