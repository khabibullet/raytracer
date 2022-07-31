/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:30:01 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/31 16:51:33 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	check_num_of_char(char *str, char ch, int num)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ch)
			++count;
		str++;
	}
	if (count != num)
		exit_error("Invalid input: invalid number of char in line");
}
