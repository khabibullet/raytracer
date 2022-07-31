/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_or_charset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:03:05 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/31 16:49:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../headers/validation.h"

void	check_digit_or_charset(char *str, char *charset)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_strchr(charset, *str))
			exit_error("Invalid input: invalid charset");
		str++;
	}
}
