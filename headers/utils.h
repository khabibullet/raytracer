/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:25:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/23 13:07:29 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
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
void	exit_error(void);

#endif
