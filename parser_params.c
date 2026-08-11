/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:58:17 by blas              #+#    #+#             */
/*   Updated: 2026/08/10 23:55:58 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	compare_extension(char *str, char *ex)
{
	int		size_pos;
	char	*pos_point;

	pos_point = ft_reverse_findchar(str, '.');
	size_pos = ft_strlen(str) - (pos_point - str);
	if (pos_point && !ft_strncmp(pos_point, ex, size_pos))
		return (1);
	else
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
