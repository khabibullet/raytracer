/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:08:09 by enoye             #+#    #+#             */
/*   Updated: 2022/07/27 18:41:06 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

void	valid_ambient(char *line)
{
	char	**params;

	check_digit_or_charset(line, " .,-\n");
	check_num_of_char(line, ',', 2);
	params = ft_split(line, ' ');
	check_num_of_fields(params, 2);
	check_ratio(params[0]);
	check_rgb(params[1]);
	free(params[0]);
	free(params[1]);
	free(params);
}
