/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:03:42 by enoye             #+#    #+#             */
/*   Updated: 2022/07/07 13:23:55 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	is_file_valid(char *name)
{
	char	*end;
	int		fd;

	if (name == 0)
		return (0);
	if (ft_strlen(name) < 3)
		return (0);
	end = name + ft_strlen(name) - 1;
	if (*end != 't' || *(end - 1) != 'r' || *(end - 2) != '.')
		return (0);
	if (open(name, O_DIRECTORY) > 0)
		return (0);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}