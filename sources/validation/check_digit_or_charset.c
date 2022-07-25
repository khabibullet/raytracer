/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_or_charset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:03:05 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/25 16:13:42 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include "../../libraries/libft/libft.h"

void	check_digit_or_charset(char *str, char *charset)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_strchr(charset, *str))
			exit_error();
		str++;
	}
}
