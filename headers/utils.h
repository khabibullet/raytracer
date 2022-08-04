/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:25:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 22:45:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 256
# include "sys/types.h"
# include <stdlib.h>

typedef struct s_var
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		red;
	char		*line;
	int			err_flag;
}	t_var;

typedef struct s_minirt	t_minirt;

char		*get_next_line(int fd);
void		exit_error(char *str);
void		exit_free(t_minirt *rt);
int			safe_atoi(const char *str);
double		ft_atof(const char *str);
void		*safe_malloc(size_t size);
long int	current_time_ms(void);

#endif
