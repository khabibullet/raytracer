/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:25:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/25 16:28:56 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 256
# include "sys/types.h"
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
void	exit_free(t_minirt *rt);
void	swap_buffers(t_minirt *rt);
int		safe_atoi(const char *str);

#endif
