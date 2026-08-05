/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:58:17 by blas              #+#    #+#             */
/*   Updated: 2026/08/05 16:49:03 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		compare_extension(char *str, char *ex)
{
	int size_pos;
	char *pos_point;

	pos_point = ft_reverse_findchar(str, '.');
	size_pos = ft_strlen(str) - (pos_point - str);
	if (pos_point && !ft_strncmp(pos_point, ex, size_pos))
		return (1);
	else
		return (0);
}


int	check_args(char **args, char *extension, int	count, int ignore)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	// if (!extension || count <= 0 || (ignore != 1 || ignore != 0))
		// return (-1);
	while (args[i])
	{
		if (ignore)
		{
			if (compare_extension(args[i], extension))
				printf("Same extension\n");
			if (count == index)
				return (index);
			index++;
		}
		else
		{
			
		}
		i++;
	}
	return (0);
}
