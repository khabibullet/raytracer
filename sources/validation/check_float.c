/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:27:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/25 19:34:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../headers/validation.h"
#include "../../libraries/libft/libft.h"

int	count_digits(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			count++;
		str++;
	}
	return (count);
}

void	check_float(char *str)
{
	char	**parts;

	if (count_digits > 8 || count_digits == 0)
		exit_error();
	parts = ft_split(str, '.');
	if (parts == NULL)
		exit_error();
	check_digit_or_charset(parts[0] + 1, "");
	if (parts[1] != NULL)
		check_digit_or_charset(parts[1], "");
}
