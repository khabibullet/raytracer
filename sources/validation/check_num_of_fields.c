/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_fields.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:17:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/31 16:54:32 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../../headers/utils.h"

void	check_num_of_fields(char **split, int num)
{
	int	count;

	if (split == NULL)
		exit_error("ft_split error");
	count = 0;
	while (*split)
	{
		split++;
		count++;
	}
	if (count != num)
		exit_error("Invalid input: invalid number of parameters in line");
}
