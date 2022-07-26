/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:23:02 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/26 17:12:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/libft/libft.h"

double	ft_atof(const char *str)
{
	double	a;
	int		e;
	char	*sign;

	a = 0.0;
	e = 0;
	sign = (char *)str;
	if (*str == '-')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
		a = a * 10.0 + (*str++ - '0');
	if (*str != '.')
		return (a);
	while ((*str++ != '\0') && ft_isdigit(*str))
	{
		a = a * 10.0 + (*str - '0');
		e -= 1;
	}
	while (e++ < 0)
		a *= 0.1;
	if (*sign == '-')
		return (-a);
	return (a);
}
