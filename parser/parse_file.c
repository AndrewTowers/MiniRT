/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:40 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/10/14 14:42:14 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	parse_file(t_data *dt)
{
	char	*str;
	char	*temp;
	char	*temp2;
	size_t	size;

	str = get_next_line(dt->fd_rt);
	while (str != NULL)
	{
		temp = ft_strtrim(str, " ");
		temp2 = ft_strtrim(str, "\t");
		size = ft_findchar(temp2, ' ') - temp2;
		if (!parse_line(temp2, dt, size))
		{
			free(temp2);
			free(temp);
			free(str);
			end_data(dt, 1, "Error\nFile bad Formatt\n");
		}
		free(str);
		free(temp);
		free(temp2);
		str = get_next_line(dt->fd_rt);
	}
	free(str);
	return (0);
}
