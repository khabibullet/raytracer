/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:29:27 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/27 17:30:02 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_char(char *str, char ch)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}
