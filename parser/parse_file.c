/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:40 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/11/10 19:11:06 by bsiguenc         ###   ########.fr       */
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
	char	*trimmed;
	char	*space_pos;
	size_t	size;
	int		res;

	trimmed = ft_strtrim(str, " \t\n\v\f\r");
	if (!trimmed || trimmed[0] == '\0' || trimmed[0] == '#')
	{
		free(trimmed);
		return (1);
	}
	space_pos = ft_strchr(trimmed, ' ');
	if (!space_pos)
		space_pos = ft_strchr(trimmed, '\t');
	if (!space_pos)
	{
		free(trimmed);
		return (ret_str("Error \n invalid line format", 0));
	}
	size = space_pos - trimmed;
	res = parse_line(trimmed, dt, size);
	free(trimmed);
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
			end_data(dt, 1, " - File bad Formatt\n");
		}
		free(str);
		str = get_next_line(dt->fd_rt);
	}
	return (0);
}
