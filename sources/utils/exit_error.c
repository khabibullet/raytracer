/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:05:40 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/31 14:50:14 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../libraries/libft/libft.h"

void	exit_error(char *str)
{
	ft_putstr_fd("Error", 1);
	if (str != NULL)
	{
		ft_putstr_fd(". ", 1);
		ft_putstr_fd(str, 1);
	}
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}
