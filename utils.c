/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:15:44 by blas              #+#    #+#             */
/*   Updated: 2026/08/05 16:43:17 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int ret_str(char *str, int status)
{
	ft_printf(str);
	return (status);
}

char *ft_findchar(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
	{
		ft_printf("Error in findchar\n");
		return (NULL);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}


char *ft_reverse_findchar(char *str, char c)
{
	int	i;

	if (!str || !c)
	{
		ft_printf("Error in findchar\n");
		return (NULL);
	}
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (NULL);
}