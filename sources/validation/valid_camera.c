/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:18:29 by enoye             #+#    #+#             */
/*   Updated: 2022/07/25 16:35:57 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"
#include "../../libraries/libft/libft.h"

void	valid_camera(char *line)
{
	char	**params;

	check_digit_or_charset(line, " .,-\n");
	check_num_of_char(line, ',', 4);
	params = ft_split(line, ' ');
	check_num_of_fields(params, 3);
	check_coords(params[0]);

	free(params[0]);
	free(params[1]);
	free(params[2]);
	free(params);
}
