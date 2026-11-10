/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:40 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/11/10 11:35:46 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

static void	clean_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	parse_single_line(t_data *dt, char *str)
{
	char	*temp;
	char	*temp2;
	size_t	size;
	int		res;

	temp = ft_strtrim(str, " ");
	temp2 = ft_strtrim(str, "\t");
	size = ft_findchar(temp2, ' ') - temp2;
	res = parse_line(temp2, dt, size);
	free(temp);
	free(temp2);
	return (res);
}

int	parse_file(t_data *dt)
{
	char	*str;

	str = get_next_line(dt->fd_rt);
	while (str != NULL)
	{
		if (!parse_single_line(dt, str))
		{
			free(str);
			clean_gnl(dt->fd_rt);
			end_data(dt, 1, "Error\nFile bad Formatt\n");
		}
		free(str);
		str = get_next_line(dt->fd_rt);
	}
	return (0);
}
