/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:18:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;

	if (n < 0)
	{
		abs = (unsigned int)(-1 * n);
		ft_putchar_fd('-', fd);
	}
	else
		abs = (unsigned int)n;
	if (abs >= 10)
		ft_putnbr_fd(abs / 10, fd);
	ft_putchar_fd(abs % 10 + '0', fd);
}
