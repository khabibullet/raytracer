/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:22:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 21:15:31 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

static int	func(t_var	*v)
{
	char	*ptr;
	char	c;

	ptr = ft_strchr(v->buf, '\n');
	if (!ptr)
	{
		v->line = ft_strjoin(v->line, v->buf);
		if (!v->line)
			return (0);
		v->buf[0] = '\0';
	}
	else
	{
		c = *(ptr + 1);
		*(ptr + 1) = '\0';
		v->line = ft_strjoin(v->line, v->buf);
		if (!v->line)
			return (0);
		*(ptr + 1) = c;
		ptr++;
		ft_strlcpy(v->buf, ptr, ft_strlen(ptr) + 1);
	}
	return (1);
}

static int	read_cat_check(t_var	*v, int fd)
{
	if (!v->red || v->buf[0] == '\0')
	{
		v->red = read(fd, v->buf, BUFFER_SIZE);
		if (v->red < 0)
		{
			free(v->line);
			v->err_flag = 1;
			return (0);
		}
		v->buf[v->red] = '\0';
	}
	if (!func(v))
	{
		v->err_flag = 1;
		return (0);
	}
	if (v->line[0] == '\0')
	{
		free(v->line);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_var	vars;

	if (fd < 0 || fd > 256 || vars.err_flag || BUFFER_SIZE <= 0)
		return (NULL);
	vars.line = malloc(sizeof(*vars.line));
	if (!vars.line)
	{
		vars.err_flag = 1;
		return (NULL);
	}
	vars.line[0] = '\0';
	while (!ft_strchr(vars.line, '\n'))
	{
		if (!read_cat_check(&vars, fd))
			return (NULL);
		if (!vars.red)
			return (vars.line);
	}
	return (vars.line);
}
