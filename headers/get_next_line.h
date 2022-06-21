/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:25:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 21:15:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 256
# include "minirt.h"

typedef struct t_var
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		red;
	char		*line;
	int			err_flag;
}	t_var;

char	*get_next_line(int fd);

#endif
