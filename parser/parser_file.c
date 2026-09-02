/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:40 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/09/02 11:51:19 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

// int	check_line(char *str, t_data *dt, size_t size)
// {
// 	if (!ft_strncmp(str, "A", size))
// 		save(dt, str + size, AML);
// 	else if (!ft_strncmp(str, "C", size))
// 		save(dt, str + size, CAM);
// 	else if (!ft_strncmp(str, "L", size))
// 		save(dt, str + size, LIGHT);
// 	else if (!ft_strncmp(str, "sp", size))
// 		save(dt, str + size, SPHERE);
// 	else if (!ft_strncmp(str, "pl", size))
// 		save(dt, str + size, PLANE);
// 	else if (!ft_strncmp(str, "cy", size))
// 		save(dt, str + size, CYLINDER);
// 	else if (!ft_strncmp(str, "\n", 1))
// 		return (1);
// 	else
// 		return (-1);
// 	return (1);
// }

// int	parse_line(char *line, t_data *dt)
// {
// 	if (!ft_strncmp(line, "A ", 2))
// 		return (parse_ambient(line + 2, dt));
// 	else if (!ft_strncmp(line, "C ", 2))
// 		return (parse_camera(line + 2, dt));
// 	else if (!ft_strncmp(line, "L ", 2))
// 		return (parse_light(line + 2, dt));
// 	else if (!ft_strncmp(line, "sp ", 3))
// 		return (parse_sphere(line + 3, dt));
// 	else if (!ft_strncmp(line, "pl ", 3))
// 		return (parse_plane(line + 3, dt));
// 	else if (!ft_strncmp(line, "cy ", 3))
// 		return (parse_cylinder(line + 3, dt));
// 	else if (!ft_strncmp(line, "\n", 1))
// 		return (1);
// 	else
// 		return (-1);
// 	return (1);
// }

int	parse_file(t_data *dt)
{
	char	*str;
	char	*temp;
	size_t	size;

	str = get_next_line(dt->fd_rt);
	while (str != NULL)
	{
		temp = ft_strtrim(str, " ");
		temp = ft_strtrim(str, "\t");
		size = ft_findchar(temp, ' ') - temp;
		if (parse_line(temp, dt, size) == -1)
		{
			free(temp);
			free(str);
			end_data(dt, 1, "Error\nFile bad Formatt\n");
		}
		free(str);
		free(temp);
		str = get_next_line(dt->fd_rt);
	}
	free(str);
	return (0);
}