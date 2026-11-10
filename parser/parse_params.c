/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:58:17 by blas              #+#    #+#             */
/*   Updated: 2026/11/10 19:08:17 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	compare_extension(char *str, char *ex)
{
	int		size_pos;
	char	*pos_point;
	char	*last_slash;

	pos_point = ft_reverse_findchar(str, '.');
	if (!pos_point)
		return (0);
	last_slash = ft_reverse_findchar(str, '/');
	if (last_slash)
	{
		if (pos_point == last_slash + 1)
			return (0);
	}
	else
	{
		if (pos_point == str)
			return (0);
	}
	size_pos = ft_strlen(str) - (pos_point - str);
	if (!ft_strncmp(pos_point, ex, size_pos))
		return (1);
	return (0);
}

int	check_args(char **args, char *extension, int count)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	if (!extension || !*args)
		return (-1);
	while (args[i])
	{
		if (!compare_extension(args[i], extension))
			return (-1);
		if (count == index)
			return (index);
		index++;
		i++;
	}
	return (0);
}
