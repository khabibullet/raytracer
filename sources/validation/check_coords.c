/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:21:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/26 17:54:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/libft/libft.h"
#include "../../headers/validation.h"

static int	count_char(char *str, char ch)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}

void	check_coords(char *coords)
{
	char	**xyz;

	xyz = ft_split(coords, ',');
	check_num_of_fields(xyz, 3);
	check_digit_or_charset(xyz[0] + 1, ".");
	check_digit_or_charset(xyz[1] + 1, ".");
	check_digit_or_charset(xyz[2] + 1, ".");
	if (count_char(xyz[0], '.') > 1
		|| count_char(xyz[1], '.') > 1
		|| count_char(xyz[2], '.') > 1)
		exit_error();
	free(xyz[0]);
	free(xyz[1]);
	free(xyz[2]);
	free(xyz);
}
